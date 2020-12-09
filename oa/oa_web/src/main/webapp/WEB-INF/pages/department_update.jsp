<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="form"  uri="http://www.springframework.org/tags/form"%>
<jsp:include page="top.jsp" />


<section id="content" class="table-layout animated fadeIn">
    <div class="tray tray-center">
        <div class="content-header">
            <h2> 编辑部门 </h2>
            <p class="lead"></p>
        </div>
        <div class="admin-form theme-primary mw1000 center-block" style="padding-bottom: 175px;">
            <div class="panel heading-border">

               <form:form action="/department/update" modelAttribute="department"  id="admin-form" name="addForm">
                <div class="panel-body bg-light">
                    <div class="section-divider mt20 mb40">
                        <span> 基本信息 </span>
                    </div>
                    <div class="section row">
                        <div class="col-md-6">
                            <label for="sn" class="field prepend-icon">
                                <form:input path="sn" cssClass="gui-input" placeholder="编号..." readonly="true"/>
                                <label for="sn" class="field-icon">
                                    <i class="fa fa-user"></i>
                                </label>
                            </label>
                        </div>
                        <div class="col-md-6">
                            <label for="name" class="field prepend-icon">
                              <form:input path="name" cssClass="gui-input" placeholder="名称..." />
                                <label for="name" class="field-icon">
                                    <i class="fa fa-user"></i>
                                </label>
                            </label>
                        </div>
                    </div>
                    <div class="section">
                        <label for="address" class="field prepend-icon">
                         <form:input path="address"   cssClass="gui-input" placeholder="地址..." />
                            <label for="address" class="field-icon">
                                <i class="fa fa-lock"></i>
                            </label>
                        </label>
                    </div>
                    <div class="panel-footer text-right">
                        <button type="submit" class="button"> 保存 </button>
                        <button type="button" class="button" onclick="javascript:window.history.go(-1);"> 返回 </button>
                    </div>
                </div>
               </form:form>

            </div>
        </div>
    </div>
</section>




<jsp:include page="bottom.jsp"/>