package game.element.vo;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

public class audionorepeat  extends Thread { //这里改你的类名
	
	  Player player;
	    File music;
	    //构造方法
	    public audionorepeat(File file) {   //构造函数也要改
	    	
	        this.music = file;
	    }
	    
	    public void loop(){
	    	this.start();
	    }
	    
	    //重写run方法
	    @Override
	    public void run() {
	      
	        try {
	        	
	            play();     
	          
	        } catch (FileNotFoundException | JavaLayerException e) {
	            // TODO Auto-generated catch block
	            e.printStackTrace();
	        }
	     
	       }
	   
	       
	    
	   
	    //播放方法
	    public void play() throws FileNotFoundException, JavaLayerException {

	            BufferedInputStream buffer =
	                    new BufferedInputStream(new FileInputStream(music));
	            player = new Player(buffer);
	            player.play();
	    }
	    
	
	



}
