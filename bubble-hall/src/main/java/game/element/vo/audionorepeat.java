package game.element.vo;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

public class audionorepeat  extends Thread { //������������
	
	  Player player;
	    File music;
	    //���췽��
	    public audionorepeat(File file) {   //���캯��ҲҪ��
	    	
	        this.music = file;
	    }
	    
	    public void loop(){
	    	this.start();
	    }
	    
	    //��дrun����
	    @Override
	    public void run() {
	      
	        try {
	        	
	            play();     
	          
	        } catch (FileNotFoundException | JavaLayerException e) {
	            // TODO Auto-generated catch block
	            e.printStackTrace();
	        }
	     
	       }
	   
	       
	    
	   
	    //���ŷ���
	    public void play() throws FileNotFoundException, JavaLayerException {

	            BufferedInputStream buffer =
	                    new BufferedInputStream(new FileInputStream(music));
	            player = new Player(buffer);
	            player.play();
	    }
	    
	
	



}
