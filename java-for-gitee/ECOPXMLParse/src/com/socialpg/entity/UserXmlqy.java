package com.opendevel.entity;

public class UserXmlqy implements UserInterface {
	private String pointTx;
	private String site_id;
	private String CompanyID ;
	private String DeptID ;
	private String StoreID ;
	private String TermID ;
	private String TxID ;
	private String TxType ;
	private String BusinessDate ;
	private String Time ;
	private String ONLStatus ;
	private String Date ;
	private String AwardType ;
	private String PointCalc ;
	private String MasterChk ;
	private String PointTargetAmount ;
	private String PointExcludeAmount ;
	private String AwardPoint ;
	private String RewardPoint;
	private String PointID ;
	private String CanTermID ;
	private String CanTxID ;
	private String CanBusinessDate;
	private String CanTime;
	
	
	
	
	
	
	public UserXmlqy() {
		super();
	}
	
	
	public UserXmlqy(String pointTx, String site_id, String companyID, String deptID, String storeID, String termID,
			String txID, String txType, String businessDate, String time, String oNLStatus, String date,
			String awardType, String pointCalc, String masterChk, String pointTargetAmount, String pointExcludeAmount,
			String awardPoint, String rewardPoint, String pointID, String canTermID, String canTxID,
			String canBusinessDate, String canTime) {
		super();
		this.pointTx = pointTx;
		this.site_id = site_id;
		CompanyID = companyID;
		DeptID = deptID;
		StoreID = storeID;
		TermID = termID;
		TxID = txID;
		TxType = txType;
		BusinessDate = businessDate;
		Time = time;
		ONLStatus = oNLStatus;
		Date = date;
		AwardType = awardType;
		PointCalc = pointCalc;
		MasterChk = masterChk;
		PointTargetAmount = pointTargetAmount;
		PointExcludeAmount = pointExcludeAmount;
		AwardPoint = awardPoint;
		RewardPoint = rewardPoint;
		PointID = pointID;
		CanTermID = canTermID;
		CanTxID = canTxID;
		CanBusinessDate = canBusinessDate;
		CanTime = canTime;
	}
	
	
	
	
	
	
	
	@Override
	public String toString() {
		return "UserXmlqy [pointTx=" + pointTx + ", site_id=" + site_id + ", CompanyID=" + CompanyID + ", DeptID="
				+ DeptID + ", StoreID=" + StoreID + ", TermID=" + TermID + ", TxID=" + TxID + ", TxType=" + TxType
				+ ", BusinessDate=" + BusinessDate + ", Time=" + Time + ", ONLStatus=" + ONLStatus + ", Date=" + Date
				+ ", AwardType=" + AwardType + ", PointCalc=" + PointCalc + ", MasterChk=" + MasterChk
				+ ", PointTargetAmount=" + PointTargetAmount + ", PointExcludeAmount=" + PointExcludeAmount
				+ ", AwardPoint=" + AwardPoint + ", RewardPoint=" + RewardPoint + ", PointID=" + PointID
				+ ", CanTermID=" + CanTermID + ", CanTxID=" + CanTxID + ", CanBusinessDate=" + CanBusinessDate
				+ ", CanTime=" + CanTime + "]";
	}


	public String getPointTx() {
		return pointTx;
	}
	public void setPointTx(String pointTx) {
		this.pointTx = pointTx;
	}
	public String getSite_id() {
		return site_id;
	}
	public void setSite_id(String site_id) {
		this.site_id = site_id;
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
	public String getTermID() {
		return TermID;
	}
	public void setTermID(String termID) {
		TermID = termID;
	}
	public String getTxID() {
		return TxID;
	}
	public void setTxID(String txID) {
		TxID = txID;
	}
	public String getTxType() {
		return TxType;
	}
	public void setTxType(String txType) {
		TxType = txType;
	}
	public String getBusinessDate() {
		return BusinessDate;
	}
	public void setBusinessDate(String businessDate) {
		BusinessDate = businessDate;
	}
	public String getTime() {
		return Time;
	}
	public void setTime(String time) {
		Time = time;
	}
	public String getONLStatus() {
		return ONLStatus;
	}
	public void setONLStatus(String oNLStatus) {
		ONLStatus = oNLStatus;
	}
	public String getDate() {
		return Date;
	}
	public void setDate(String date) {
		Date = date;
	}
	public String getAwardType() {
		return AwardType;
	}
	public void setAwardType(String awardType) {
		AwardType = awardType;
	}
	public String getPointCalc() {
		return PointCalc;
	}
	public void setPointCalc(String pointCalc) {
		PointCalc = pointCalc;
	}
	public String getMasterChk() {
		return MasterChk;
	}
	public void setMasterChk(String masterChk) {
		MasterChk = masterChk;
	}
	public String getPointTargetAmount() {
		return PointTargetAmount;
	}
	public void setPointTargetAmount(String pointTargetAmount) {
		PointTargetAmount = pointTargetAmount;
	}
	public String getPointExcludeAmount() {
		return PointExcludeAmount;
	}
	public void setPointExcludeAmount(String pointExcludeAmount) {
		PointExcludeAmount = pointExcludeAmount;
	}
	public String getAwardPoint() {
		return AwardPoint;
	}
	public void setAwardPoint(String awardPoint) {
		AwardPoint = awardPoint;
	}
	public String getRewardPoint() {
		return RewardPoint;
	}
	public void setRewardPoint(String rewardPoint) {
		RewardPoint = rewardPoint;
	}
	public String getPointID() {
		return PointID;
	}
	public void setPointID(String pointID) {
		PointID = pointID;
	}
	public String getCanTermID() {
		return CanTermID;
	}
	public void setCanTermID(String canTermID) {
		CanTermID = canTermID;
	}
	public String getCanTxID() {
		return CanTxID;
	}
	public void setCanTxID(String canTxID) {
		CanTxID = canTxID;
	}
	public String getCanBusinessDate() {
		return CanBusinessDate;
	}
	public void setCanBusinessDate(String canBusinessDate) {
		CanBusinessDate = canBusinessDate;
	}
	public String getCanTime() {
		return CanTime;
	}
	public void setCanTime(String canTime) {
		CanTime = canTime;
	}
	
	
	
	
	
	
}
