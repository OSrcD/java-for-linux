package com.opendev.domain.manager;

import com.opendev.domain.Users;
import org.kurento.client.KurentoClient;
import org.springframework.stereotype.Component;

import java.util.concurrent.ConcurrentHashMap;

@Component
public class UserManager {

    public static KurentoClient kurentoClient = KurentoClient.create();

    public static ConcurrentHashMap<String, Users>  users = new ConcurrentHashMap<String, Users>();

}
