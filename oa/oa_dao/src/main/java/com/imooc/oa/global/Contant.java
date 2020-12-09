package com.imooc.oa.global;


import java.util.ArrayList;
import java.util.List;

public class Contant {
    public static final String POST_STAFF = "员工";
    public static final String POST_FM = "部门经理";
    public static final String POST_GM = "总经理";
    public static final String  POST_CASHIER = "财务";

    public static   List<String> getPosts(){
        List<String> list = new ArrayList<String>();
        list.add(POST_STAFF);
        list.add(POST_FM);
        list.add(POST_GM);
        list.add(POST_CASHIER);

        return list;
    }


    public static List<String> getItems(){
        List<String> list = new ArrayList<String>();
        list.add("交通");
        list.add("餐饮");
        list.add("住宿");
        list.add("办公");
        return list;
    }


    public static final String CLAIM_VOUCHER_CREATED = "新创建";
    public static final String CLAIM_VOUCHER_SUBMIT = "已提交";
    public static final String CLAIM_VOUCHER_APPROVED = "已审核";
    public static final String CLAIM_VOUCHER_BACK_  = "已打回";
    public static final String CLAIM_VOUCHER_RECHECK  = "待复审";
    public static final String CLAIM_VOUCHER_PAID  = "已打款";
    public static final String CLAIM_VOUCHER_TERMINATED  = "已终止";

    public static final Double LIMIT_CHECK = 5000.00;

    public static final String DEAL_CREATE = "创建";
    public static final String DEAL_SUBMIT = "提交";
    public static final String DEAL_UPDATE = "修改";
    public static final String DEAL_BACK = "打回";
    public static final String DEAL_REJECT = "拒绝";
    public static final String DEAL_PASS = "通过";
    public static final String DEAL_PAID = "打款";






}
