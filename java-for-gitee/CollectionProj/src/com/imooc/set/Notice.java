package com.imooc.set;
import java.util.Date;
public class Notice {
	private int id;
	private String title;
	private String creator;
	private Date createTime;

	public Notice(int id, String title, String creator, Date createTime) {
		super();
		this.id = id;
		this.title = title;
		this.creator = creator;
		this.createTime = createTime;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getCreator() {
		return creator;
	}

	public void setCreator(String creator) {
		this.creator = creator;
	}

	public Date getCreateTime() {
		return createTime;
	}

	public void setCreateTime(Date createTime) {
		this.createTime = createTime;
	} 
	
	
	
}
