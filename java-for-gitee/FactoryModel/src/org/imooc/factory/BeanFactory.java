package org.imooc.factory;

import org.imooc.component.Arms;
import org.imooc.component.Hair;
import org.imooc.plant.Bean;
import org.imooc.plant.Plant;
/*
工厂与创建对象封装
 */
public class BeanFactory implements Factory {
    public Plant createPlant(){
        Bean bean = new Bean();
        Hair hair = new Hair();
        hair.setColor("绿色");
        bean.setHair(hair);
        Arms arms = new Arms();
        arms.setBulletType("普通的豆子");
        bean.setArms(arms);
        return bean;
    }

}
