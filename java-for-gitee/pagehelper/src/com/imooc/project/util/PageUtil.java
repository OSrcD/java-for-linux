package com.imooc.project.util;

import java.util.List;

/**
 * create by imooc
 */
public class PageUtil {
	
	private int currentPageNum; //当前要看哪一页
	
	private int pageSize=10;//每页显示的条数
	
	private int totalSize;//总记录条数
	
	private int startIndex;//查询开始记录的索引 limit ? ?
	
	private int totalPageNum;//总页数
	
	private int prePageNum;//上一页
	
	private int nextPageNum;//下一页
	
	private List  records;//当前页的记录集
	
	
	//用于显示页面上的导航的页号  用户可自定义
	
	private int startPageNum;
	
	private int endPageNum;
	
	private String url;
	
	
	//使用构造方法，传递必要的两个参数.第一个是页码，第二个总记录条数
	public PageUtil(int currentPageNum,int totalrecords)
	{
		this.currentPageNum=currentPageNum;
		this.totalSize=totalrecords;
		//计算开始记录索引
		startIndex=(currentPageNum-1)*pageSize;
		//计算总页数
		totalPageNum=totalSize%pageSize==0?totalSize/pageSize:totalSize/pageSize+1;
		//计算开始和结束页号  这个根据自身可设计
		if(totalPageNum>9)
		{
			startPageNum=currentPageNum-4;
			endPageNum=currentPageNum+4;

			if(startPageNum<1)
			{
				startPageNum=1;
				endPageNum=startPageNum+8;
			}
			if(endPageNum>totalPageNum)
			{
				endPageNum=totalPageNum;
				startPageNum=endPageNum-8;
			}
			
		}
		else
		{
			startPageNum=1;
			endPageNum=totalPageNum;

		}
		

	}
	

     public int getStartPageNum() {
		return startPageNum;
	}


	public void setStartPageNum(int startPageNum) {
		this.startPageNum = startPageNum;
	}


	public int getEndPageNum() {
		return endPageNum;
	}


	public void setEndPageNum(int endPageNum) {
		this.endPageNum = endPageNum;
	}


	public int getPrePageNum() {
		prePageNum=currentPageNum-1;
		
		if(prePageNum<=0)
		{
			prePageNum=1;
		}
		return prePageNum;
	}

	public int getNextPageNum() {
		
		nextPageNum=currentPageNum+1;
		
		if(nextPageNum>totalPageNum)
		{
			nextPageNum=totalPageNum;
		}
		return nextPageNum;
	}

	public int getCurrentPageNum() {
		return currentPageNum;
	}

	public void setCurrentPageNum(int currentPageNum) {
		this.currentPageNum = currentPageNum;
	}

	public int getPageSize() {
		return pageSize;
	}

	public void setPageSize(int pageSize) {
		this.pageSize = pageSize;
	}

	public int getTotalSize() {
		return totalSize;
	}

	public void setTotalSize(int totalSize) {
		this.totalSize = totalSize;
	}

	public int getStartIndex() {
		return startIndex;
	}

	public void setStartIndex(int startIndex) {
		this.startIndex = startIndex;
	}

	public int getTotalPageNum() {
		return totalPageNum;
	}

	public void setTotalPageNum(int totalPageNum) {
		this.totalPageNum = totalPageNum;
	}

	public List  getRecords() {
		return records;
	}

	public void setRecords(List  records) {
		this.records = records;
	}

	public void setPrePageNum(int prePageNum) {
		this.prePageNum = prePageNum;
	}

	public void setNextPageNum(int nextPageNum) {
		this.nextPageNum = nextPageNum;
	}


	public String getUrl() {
		return url;
	}


	public void setUrl(String url) {
		this.url = url;
	}
	
	
	
	

}
