package org.imooc.plant;

import org.imooc.component.Shell;

public class Wall implements Plant {

    private Shell shell;

    public String getName(){
        return "果墙";
    }

    public void fight(){
        System.out.println("稳稳的站在草地上");
    }

    public Shell getShell() {
        return shell;
    }

    public void setShell(Shell shell) {
        this.shell = shell;
    }
}
