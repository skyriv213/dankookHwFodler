package com.example.demo.chat;

import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.messaging.handler.annotation.DestinationVariable;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.handler.annotation.SendTo;
import org.springframework.messaging.simp.SimpMessageSendingOperations;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Controller
@RequiredArgsConstructor
@Slf4j
public class PubController {

    private final SimpMessageSendingOperations operations;

    // /pub/channel
    @MessageMapping("/rooms/{roomId}")
    @SendTo("/topic/rooms/{roomId}")
    public Message sendMessage(@DestinationVariable Long roomId, Message message) {
//        operations.convertAndSend
//            ("/sub/channel/" + roomId, message);
        log.info("메세지 전송 성공");

        return message;
    }
}
