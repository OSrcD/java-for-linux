package com.imooc.project.entity;

import java.util.List;

/**
 * @author imooc
 */
public class Dept {
	
	private Integer id;
	
	private String departmentName;
	
	private List<Person> persons;
	
	public Dept(Integer id) {
		super();
		this.id = id;
	}
	
	public Dept() {
		super();
		 
	}

	@Override
	public String toString() {
		return "Dept{" +
				"id=" + id +
				", departmentName='" + departmentName + '\'' +
				", persons=" + persons +
				'}';
	}

	public List<Person> getPersons() {
		return persons;
	}

	public void setPersons(List<Person> persons) {
		this.persons = persons;
	}

	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getDepartmentName() {
		return departmentName;
	}
	public void setDepartmentName(String departmentName) {
		this.departmentName = departmentName;
	}
	 
	
	

}
