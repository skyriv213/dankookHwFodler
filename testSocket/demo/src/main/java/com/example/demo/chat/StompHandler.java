package com.example.demo.chat;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.core.Ordered;
import org.springframework.core.annotation.Order;
import org.springframework.messaging.MessageChannel;
import org.springframework.messaging.simp.stomp.StompCommand;
import org.springframework.messaging.simp.stomp.StompHeaderAccessor;
import org.springframework.messaging.support.ChannelInterceptor;
import org.springframework.stereotype.Component;

@Slf4j
@RequiredArgsConstructor
@Component
@Order(Ordered.HIGHEST_PRECEDENCE + 99)
public class StompHandler implements ChannelInterceptor {

    private final JwtUtil jwtUtil;

    // websocket을 통해 들어온 요청이 처리 되기전 실행됨
//    @Override
//    public Message<?> preSend(Message<?> message, MessageChannel channel) {
////        StompHeaderAccessor accessor = StompHeaderAccessor.wrap(message);
////        // websocket 연결시 헤더의 jwt token 유효성 검증
////        if (StompCommand.CONNECT == accessor.getCommand()) {
////            String authorization = jwtUtil.validateToken(accessor.getFirstNativeHeader("Authorization"));
////            jwtUtil.parseClaims(authorization);
////        }
//        return message;
//    }
}