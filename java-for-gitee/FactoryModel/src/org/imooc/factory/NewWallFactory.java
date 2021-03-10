package org.imooc.factory;

import org.imooc.component.Shell;
import org.imooc.plant.Plant;
import org.imooc.plant.Wall;

public class NewWallFactory implements Factory {

    public Plant createPlant(){
        Wall wall = new Wall();
        Shell shell = new Shell();
        shell.setHardness(10);
        wall.setShell(shell);
        return wall;
    }
}
