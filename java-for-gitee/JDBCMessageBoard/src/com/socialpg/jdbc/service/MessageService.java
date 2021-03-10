package com.opendevel.jdbc.service;

import com.opendevel.jdbc.bean.Message;
import com.opendevel.jdbc.dao.MessageDao;

import java.util.Date;
import java.util.List;

/**
 *
 */
public class MessageService {

    private MessageDao messageDao;

    public  MessageService(){
        messageDao = new MessageDao();
    }

    public boolean addMessage(Message message){
        message.setCreateTime(new Date());
        System.out.println(new Date());
        return  messageDao.save(message);
    }




    public List<Message> getMessages(int page,int pageSize){
        /**
         * 分页查询全部留言
         * @param page 当前页码
         * @param pageSize 每页记录数
         * @return
         */
        return messageDao.getMessages(page, pageSize);
    }

    public  int countMessages(){
        return messageDao.countMessages();
    }

}
