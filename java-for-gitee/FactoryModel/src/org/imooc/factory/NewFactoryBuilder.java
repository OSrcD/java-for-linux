package org.imooc.factory;

import org.imooc.plant.PlantNameConstant;

/**
 * 新游戏的构建工厂
 */

public class NewFactoryBuilder {
    public static Factory build(String name){
        Factory factory =null;

        if("几十种植物".equals(name)){

        }if(PlantNameConstant.BEAN_NAME.equals(name)){
            factory = new BeanFactory();
        }else if(PlantNameConstant.ICE_NAME.equals(name)){
            factory = new IceFactory();
        }else if (PlantNameConstant.WALL_NAME.equals(name)){
            factory = new NewWallFactory();
        }

        return factory;
    }
}
