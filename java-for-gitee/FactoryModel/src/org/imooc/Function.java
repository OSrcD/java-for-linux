package org.imooc;

import org.imooc.factory.Factory;
import org.imooc.factory.FactoryBuilder;
import org.imooc.factory.SimpleFactory;
import org.imooc.plant.Bean;
import org.imooc.plant.Ice;
import org.imooc.plant.Plant;
import org.imooc.plant.Wall;



public class Function {
    public void put(String name,int number) throws Exception{
        Factory factory =  FactoryBuilder.buildByClassName(name);
        Plant plant =  factory.createPlant();
        System.out.println("将"+plant.getName()+"放在"+number+"号草地上");
        plant.fight();
    }
}
