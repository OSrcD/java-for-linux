package com.opendevel.dnf;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class DnfDump    {

	static {
		System.loadLibrary("DnfDump");
	}
	
	public DnfDump() {
		
	

	}
	
	
	public static native  void dump();
	
	
	public static void main(String[] args) {
		JFrame Frame = new JFrame();
		Frame.setTitle("DNFDumpTools");
		Frame.setSize(350,200);
		Frame.setDefaultCloseOperation(Frame.EXIT_ON_CLOSE);
		Frame.setLocationRelativeTo(null);
		JPanel jPanel = new JPanel();
		
		JButton jButton = new JButton("dump");
		jButton.setLocation(150, 500);
	
		Frame.setContentPane(jPanel);
		jPanel.add(jButton);
		Frame.setVisible(true);

		jButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				DnfDump.dump();
			}
		});
	}

}
