package com.imooc.user.stream;

import org.springframework.cloud.stream.annotation.Input;
import org.springframework.cloud.stream.annotation.Output;
import org.springframework.messaging.SubscribableChannel;

public interface ForceLogoutTopic {

    String INPUT = "force-logout-consumer";

    String OUTPUT = "force-logout-producer";

    @Input(INPUT)
    SubscribableChannel input();

    @Output(OUTPUT)
    SubscribableChannel output();
}
