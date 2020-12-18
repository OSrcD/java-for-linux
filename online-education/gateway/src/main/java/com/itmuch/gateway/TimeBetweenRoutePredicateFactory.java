package com.itmuch.gateway;

import org.springframework.cloud.gateway.handler.predicate.AbstractRoutePredicateFactory;
import org.springframework.format.annotation.DateTimeFormat;
import org.springframework.stereotype.Component;
import org.springframework.web.server.ServerWebExchange;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.format.FormatStyle;
import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;

@Component
public class TimeBetweenRoutePredicateFactory extends AbstractRoutePredicateFactory<TimeBeweenConfig> {
    public TimeBetweenRoutePredicateFactory() {
        super(TimeBeweenConfig.class);
    }

    @Override
    public Predicate<ServerWebExchange> apply(TimeBeweenConfig config) {
        LocalTime start = config.getStart();
        LocalTime end = config.getEnd();
        return exchange -> {
            LocalTime now = LocalTime.now();
            return now.isAfter(start) && now.isBefore(end);
        };
    }


    public static void main(String[] args) {
        DateTimeFormatter formatter = DateTimeFormatter.ofLocalizedTime(FormatStyle.SHORT);
        System.out.println(formatter.format(LocalTime.now()));
    }

    @Override
    public List<String> shortcutFieldOrder() {
        return Arrays.asList("start","end");
    }
}
