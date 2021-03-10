package org.imooc.factory;

import org.imooc.component.Arms;
import org.imooc.component.Hair;
import org.imooc.plant.Ice;
import org.imooc.plant.Plant;

/*
工厂与创建对象封装
 */
public class IceFactory  implements Factory {

    public Plant createPlant(){
        Ice ice = new Ice();
        Hair hair = new Hair();
        hair.setColor("蓝色");
        ice.setHair(hair);
        Arms arms = new Arms();
        arms.setBulletType("冰冻的豆子");

        ice.setArms(arms);

        return ice;

    }
}
