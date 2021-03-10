package com.mooc.service;

import com.mooc.beans.Xbean;

public interface XbeanService {
    Xbean getXbean(int id);
    void insertXbean(Xbean xb);
}
