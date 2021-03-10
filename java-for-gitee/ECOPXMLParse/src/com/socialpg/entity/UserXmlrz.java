package com.opendevel.entity;

public class UserXmlrz implements UserInterface  {
	private String pointTx;
	private String site_id;
	private String CompanyID;
	private String DeptID;
	private String StoreID;
	private String TxType;
	private String Date;
	private String Status;
	private String ErrorMsg;
	private String Param1;
	private String Param2;
	private String Param3;
	private String Param4;
	private String Param5;
	
	
	
	
	public UserXmlrz() {
		
	}
	
	
	public UserXmlrz(String pointTx, String site_id, String companyID, String deptID, String storeID, String txType,
			String date, String status, String errorMsg, String param1, String param2, String param3, String param4,
			String param5) {
		super();
		this.pointTx = pointTx;
		this.site_id = site_id;
		CompanyID = companyID;
		DeptID = deptID;
		StoreID = storeID;
		TxType = txType;
		Date = date;
		Status = status;
		ErrorMsg = errorMsg;
		Param1 = param1;
		Param2 = param2;
		Param3 = param3;
		Param4 = param4;
		Param5 = param5;
	}
	public String getPointTx() {
		return pointTx;
	}
	public void setPointTx(String pointTx) {
		this.pointTx = pointTx;
	}
	public String getCompanyID() {
		return CompanyID;
	}
	public void setCompanyID(String companyID) {
		CompanyID = companyID;
	}
	public String getDeptID() {
		return DeptID;
	}
	public void setDeptID(String deptID) {
		DeptID = deptID;
	}
	public String getStoreID() {
		return StoreID;
	}
	public void setStoreID(String storeID) {
		StoreID = storeID;
	}
	public String getTxType() {
		return TxType;
	}
	public void setTxType(String txType) {
		TxType = txType;
	}
	public String getDate() {
		return Date;
	}
	public void setDate(String date) {
		Date = date;
	}
	public String getStatus() {
		return Status;
	}
	public void setStatus(String status) {
		Status = status;
	}
	public String getErrorMsg() {
		return ErrorMsg;
	}
	public void setErrorMsg(String errorMsg) {
		ErrorMsg = errorMsg;
	}
	public String getParam1() {
		return Param1;
	}
	public void setParam1(String param1) {
		Param1 = param1;
	}
	public String getParam2() {
		return Param2;
	}
	public void setParam2(String param2) {
		Param2 = param2;
	}
	public String getParam3() {
		return Param3;
	}
	public void setParam3(String param3) {
		Param3 = param3;
	}
	public String getParam4() {
		return Param4;
	}
	public void setParam4(String param4) {
		Param4 = param4;
	}
	public String getParam5() {
		return Param5;
	}
	public void setParam5(String param5) {
		Param5 = param5;
	}
	@Override
	public String toString() {
		return "User [pointTx=" + pointTx + ", CompanyID=" + CompanyID + ", DeptID=" + DeptID + ", StoreID=" + StoreID
				+ ", TxType=" + TxType + ", Date=" + Date + ", Status=" + Status + ", ErrorMsg=" + ErrorMsg
				+ ", Param1=" + Param1 + ", Param2=" + Param2 + ", Param3=" + Param3 + ", Param4=" + Param4
				+ ", Param5=" + Param5 + "]";
	}
	
	
	
	

}
