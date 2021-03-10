package com.opendevel.sax.handler;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class MukeHandler extends DefaultHandler {
	private String currentTag;
	
	@Override
	public void startDocument() throws SAXException {
		System.out.println("�����ĵ���ʼ");
	}

	@Override
	public void endDocument() throws SAXException {
		System.out.println("�����ĵ�����");
	}

	@Override
	public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
		System.out.println("��ʼ����Ԫ�أ�"+qName);
		currentTag=qName;
		if(attributes.getLength()>0) {
			System.out.println("<"+currentTag+">Ԫ�ص���������:");
			
			for(int i=0;i<attributes.getLength();i++) {
				System.out.println(attributes.getQName(i)+"--->"+attributes.getValue(i));
			}
		}
	}

	@Override
	public void endElement(String uri, String localName, String qName) throws SAXException {
		System.out.println("����Ԫ�ؽ���"+qName);
	}

	@Override
	public void characters(char[] ch, int start, int length) throws SAXException {

		super.characters(ch, start, length);
		String content = new String(ch,start,length);
		if(content.trim().length()>0) {
			System.out.println("<"+currentTag+">Ԫ�ص�ֵ��:"+content.trim());
		}
	}

}
