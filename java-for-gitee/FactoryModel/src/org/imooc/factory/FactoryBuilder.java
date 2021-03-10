package org.imooc.factory;

import org.imooc.plant.Plant;
import org.imooc.plant.PlantNameConstant;

public class FactoryBuilder {
    /**
     * 只负责创建工厂，不负责创建对象
     * @param name
     * @return
     */
    public static Factory build(String name){
        Factory factory = null;
        if(PlantNameConstant.BEAN_NAME.equals(name)){
            factory = new BeanFactory();

        }else if(PlantNameConstant.ICE_NAME.equals(name)){
            factory = new IceFactory();

        }else if(PlantNameConstant.WALL_NAME.equals(name)){
            factory = new WallFactory();

        }

        return factory;
    }

    public  static Factory buildByClassName(String name) throws Exception {
        return  (Factory)Class.forName(name).newInstance();
    }


}
