"use strict";

var canvas;
var gl;

var numVertices = 18;

var pointsArray = [];
var normalsArray = [];


var vertices = [
    vec4(0.0, 1.0, 0.0, 1.0),  // Apex
    vec4(-0.5, 0.0, -0.5, 1.0), // Base - left back
    vec4(0.5, 0.0, -0.5, 1.0),  // Base - right back
    vec4(-0.5, 0.0, 0.5, 1.0),   // Base - left front
    vec4(0.5, 0.0, 0.5, 1.0)   // Base - right front
];

var vertexColors = [
    vec4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
    vec4( 0.0, 1.0, 0.0, 1.0 ),  // green
    vec4( 0.0, 0.0, 1.0, 1.0 ),  // blue
    vec4( 1.0, 0.0, 1.0, 1.0 ),  // magenta
    vec4( 0.0, 1.0, 1.0, 1.0 ),  // cyan
    vec4( 1.0, 1.0, 1.0, 1.0 )   // white
];
var colors = [];
var speed = 100;
var direction = 1;

var lightPosition = vec4(1.0, 1.0, 1.0, 0.0);
var lightAmbient = vec4(0.2, 0.2, 0.2, 1.0);
var lightDiffuse = vec4(1.0, 1.0, 1.0, 1.0);
var lightSpecular = vec4(1.0, 1.0, 1.0, 1.0);

var materialAmbient = vec4(1.0, 0.0, 1.0, 1.0);
var materialDiffuse = vec4(1.0, 0.8, 0.0, 1.0);
var materialSpecular = vec4(1.0, 0.8, 0.0, 1.0);
var materialShininess = 100.0;

var ctm;
var ambientColor, diffuseColor, specularColor;
var modelView, projection;
var viewerPos;
var program;

var xAxis = 0;
var yAxis = 1;
var zAxis = 2;
var axis = 0;
var theta = [0, 0, 0];

var thetaLoc;

var flag = true;


function colorPyramid() {
    quad( 1, 2, 4 ,3 );

    triangle(0, 1, 2);
    triangle(0, 4, 3);
    triangle(0, 1, 3);
    triangle(0, 4, 2);
}

function quad(a, b, c, d) {

    var indices = [ a, b, c, a, c, d ];

    var t1 = subtract(vertices[b], vertices[a]);
    var t2 = subtract(vertices[c], vertices[b]);
    var normal = cross(t1, t2);
    var normal = vec3(normal);

    for(var i =0;i<indices.length;++i){
        pointsArray.push(vertices[indices[i]]);
        normalsArray.push(normal);
        colors.push(vertexColors[i])
    }
}

function triangle(a, b, c) {

    var indices = [ a, b, c ];

    var t1 = subtract(vertices[b], vertices[a]);
    var t2 = subtract(vertices[b], vertices[c]);
    var normal = cross(t1, t2);
    normal = normalize(normal);

    for(var i = 0; i<3;++i){
        pointsArray.push(vertices[indices[i]]);
        normalsArray.push(normal);
        colors.push(vertexColors[i]);
    }
}

window.onload = function init() {
    canvas = document.getElementById( "gl-canvas" );

    gl = WebGLUtils.setupWebGL( canvas );
    if ( !gl ) { alert( "WebGL isn't available" ); }

    var pointsBuffer = gl.createBuffer();
    var colorsBuffer = gl.createBuffer();

    gl.bindBuffer(gl.ARRAY_BUFFER, pointsBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, 16 * numVertices, gl.STATIC_DRAW);

    gl.bindBuffer(gl.ARRAY_BUFFER, colorsBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, 16 * numVertices, gl.STATIC_DRAW);

    gl.viewport( 0, 0, canvas.width, canvas.height );
  
    gl.clearColor( 1.0, 1.0, 1.0, 1.0 );
    gl.enable(gl.DEPTH_TEST);
    //
    //  Load shaders and initialize attribute buffers
    //
    program = initShaders( gl, "vertex-shader", "fragment-shader" );
    gl.useProgram( program );

    colorPyramid();

    // 컬러를 위해 추가
    var cBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, cBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, flatten(colors), gl.STATIC_DRAW);

    var vColor = gl.getAttribLocation(program, "vColor");
    gl.vertexAttribPointer(vColor, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vColor);

    //------

    var nBuffer = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, nBuffer );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(normalsArray), gl.STATIC_DRAW );

    var vNormal = gl.getAttribLocation( program, "vNormal" );
    gl.vertexAttribPointer( vNormal, 3, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vNormal );

    var vBuffer = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(pointsArray), gl.STATIC_DRAW );

    var vPosition = gl.getAttribLocation(program, "vPosition");
    gl.vertexAttribPointer(vPosition, 4, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(vPosition);

    thetaLoc = gl.getUniformLocation(program, "theta");

    viewerPos = vec3(0.0, 0.0, -20.0 );

    projection = ortho(-1, 1, -1, 1, -100, 100);

    var ambientProduct = mult(lightAmbient, materialAmbient);
    var diffuseProduct = mult(lightDiffuse, materialDiffuse);
    var specularProduct = mult(lightSpecular, materialSpecular);

    document.getElementById("ButtonX").onclick = function(){axis = xAxis;};
    document.getElementById("ButtonY").onclick = function(){axis = yAxis;};
    document.getElementById("ButtonZ").onclick = function(){axis = zAxis;};
    document.getElementById("ButtonT").onclick = function(){flag = !flag;};

    

    // document.getElementById("Direction").onclick = function (event) {
    //     direction = !direction;
    // };

    // document.getElementById("Controls").onclick = function( event) {
    //     switch(event.target.index) {
    //       case 0:
    //         direction = !direction;
    //         break;

    //      case 1:
    //         speed /= 2.0;
    //         break;

    //      case 2:
    //         speed *= 2.0;
    //         break;
    //    }
    // };
    document.getElementById("ButtonFaster").onclick = function () {
        speed *= 2.0;  // 현재 속도를 두 배로 증가
    };

    document.getElementById("ButtonSlower").onclick = function () {
        speed /= 2.0;  // 현재 속도를 절반으로 감소
    };
    document.getElementById("ButtonReverse").onclick = function () {
        direction *= -1;  // 회전 방향을 반대로 변경
    };
    thetaLoc = gl.getUniformLocation(program, "theta");


    gl.uniform4fv(gl.getUniformLocation(program, "ambientProduct"),
       flatten(ambientProduct));
    gl.uniform4fv(gl.getUniformLocation(program, "diffuseProduct"),
       flatten(diffuseProduct) );
    gl.uniform4fv(gl.getUniformLocation(program, "specularProduct"),
       flatten(specularProduct) );
    gl.uniform4fv(gl.getUniformLocation(program, "lightPosition"),
       flatten(lightPosition) );

    gl.uniform1f(gl.getUniformLocation(program,
       "shininess"),materialShininess);

    gl.uniformMatrix4fv( gl.getUniformLocation(program, "projectionMatrix"),
       false, flatten(projection));

  
    
    render();

};

var render = function () {
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    

    if (flag) theta[axis] += 2.0 * speed * direction / 100;

    modelView = mat4();
    modelView = mult(modelView, rotate(theta[xAxis], [1, 0, 0]));
    modelView = mult(modelView, rotate(theta[yAxis], [0, 1, 0]));
    modelView = mult(modelView, rotate(theta[zAxis], [0, 0, 1]));

    gl.uniformMatrix4fv(gl.getUniformLocation(program, "modelViewMatrix"), false, flatten(modelView));



    gl.drawArrays(gl.TRIANGLES, 0, pointsArray.length);

    requestAnimFrame(render);
};
