package org.imooc.factory;

import org.imooc.component.Hair;
import org.imooc.component.Shell;
import org.imooc.plant.Plant;
import org.imooc.plant.Wall;

/**
 * wall工厂与创建对象封装
 */
public class WallFactory implements Factory {

    public Plant createPlant(){

        Wall wall = new Wall();
        Shell shell = new Shell();
        shell.setHardness(5);
        wall.setShell(shell);
        return wall;

    }


}
