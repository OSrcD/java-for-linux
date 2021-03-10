package org.imooc.factory;

import org.imooc.component.Arms;
import org.imooc.component.Hair;
import org.imooc.component.Shell;
import org.imooc.plant.*;

public class SimpleFactory {

    /**
     * 创建植物对象的静态方法
     * @param name
     * @return
     */

    public static Plant  createPlant(String name){
        Plant plant = null;
        if(PlantNameConstant.BEAN_NAME.equals(name)){
            Bean bean = new Bean();
            Hair hair = new Hair();
            hair.setColor("绿色");
            bean.setHair(hair);
            Arms arms = new Arms();
            arms.setBulletType("普通的豆子");
            bean.setArms(arms);
            plant = bean;
        }else if(PlantNameConstant.ICE_NAME.equals(name)){
            Ice ice = new Ice();
            Hair hair = new Hair();
            hair.setColor("蓝色");
            ice.setHair(hair);
            Arms arms = new Arms();
            arms.setBulletType("冰冻的豆子");
            ice.setArms(arms);
            plant = ice;
        }else if(PlantNameConstant.WALL_NAME.equals(name)){
            Wall wall = new Wall();
            Shell shell = new Shell();
            shell.setHardness(5);
            wall.setShell(shell);
            plant = wall;

        }

        return plant;

    }

    public static Plant createPlantByClassName(String name) throws Exception {


            return (Plant)Class.forName(name).newInstance();

    }


}
