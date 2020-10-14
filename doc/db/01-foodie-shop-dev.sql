DROP TABLE carousel;;/*SkipError*/
CREATE TABLE carousel(
    id VARCHAR(64) NOT NULL   COMMENT '主键' ,
    image_url VARCHAR(128) NOT NULL   COMMENT '图片 图片地址' ,
    background_color VARCHAR(32)    COMMENT '背景色 背景颜色' ,
    item_id VARCHAR(64)    COMMENT '商品id 商品id' ,
    cat_id VARCHAR(64)    COMMENT '商品分类id 商品分类id' ,
    type INT NOT NULL   COMMENT '轮播图类型 轮播图类型，用于判断，可以根据商品id或者分类进行页面跳转，1：商品 2：分类' ,
    sort INT NOT NULL   COMMENT '轮播图展示顺序 轮播图展示顺序，从小到大' ,
    is_show INT NOT NULL   COMMENT '是否展示 是否展示，1：展示    0：不展示' ,
    create_time DATETIME NOT NULL   COMMENT '创建时间 创建时间' ,
    update_time DATETIME NOT NULL   COMMENT '更新时间 更新' ,
    PRIMARY KEY (id)
) COMMENT = '轮播图 ';;

ALTER TABLE carousel COMMENT '轮播图';;
DROP TABLE category;;/*SkipError*/
CREATE TABLE category(
    id INT NOT NULL AUTO_INCREMENT  COMMENT '主键 分类id主键' ,
    name VARCHAR(32) NOT NULL   COMMENT '分类名称 分类名称' ,
    type INT NOT NULL   COMMENT '分类类型 分类得类型，
1:一级大分类
2:二级分类
3:三级小分类' ,
    father_id INT NOT NULL   COMMENT '父id 父id 上一级依赖的id，1级分类则为0，二级三级分别依赖上一级' ,
    logo VARCHAR(64)    COMMENT '图标 logo' ,
    slogan VARCHAR(64)    COMMENT '口号' ,
    cat_image VARCHAR(64)    COMMENT '分类图' ,
    bg_color VARCHAR(32)    COMMENT '背景颜色' ,
    PRIMARY KEY (id)
) COMMENT = '商品分类 ';;

ALTER TABLE category COMMENT '商品分类';;
DROP TABLE users;;/*SkipError*/
CREATE TABLE users(
    id VARCHAR(64) NOT NULL   COMMENT '主键id 用户id' ,
    username VARCHAR(32) NOT NULL   COMMENT '用户名 用户名' ,
    password VARCHAR(64) NOT NULL   COMMENT '密码 密码' ,
    nickname VARCHAR(32)    COMMENT '昵称 昵称' ,
    realname VARCHAR(128)    COMMENT '真实姓名 真实姓名' ,
    face VARCHAR(1024) NOT NULL   COMMENT '头像 头像' ,
    mobile VARCHAR(32)    COMMENT '手机号 手机号' ,
    email VARCHAR(32)    COMMENT '邮箱地址 邮箱地址' ,
    sex INT    COMMENT '性别 性别 1:男  0:女  2:保密' ,
    birthday DATE    COMMENT '生日 生日' ,
    created_time DATETIME NOT NULL   COMMENT '创建时间 创建时间' ,
    updated_time DATETIME NOT NULL   COMMENT '更新时间 更新时间' ,
    PRIMARY KEY (id)
) COMMENT = '用户表 ';;

ALTER TABLE users ADD UNIQUE username(username);;
ALTER TABLE users COMMENT '用户表';;
DROP TABLE user_address;;/*SkipError*/
CREATE TABLE user_address(
    id VARCHAR(64) NOT NULL   COMMENT '地址主键id' ,
    user_id VARCHAR(64) NOT NULL   COMMENT '关联用户id' ,
    receiver VARCHAR(32) NOT NULL   COMMENT '收件人姓名' ,
    mobile VARCHAR(32) NOT NULL   COMMENT '收件人手机号' ,
    province VARCHAR(32) NOT NULL   COMMENT '省份' ,
    city VARCHAR(32) NOT NULL   COMMENT '城市' ,
    district VARCHAR(32) NOT NULL   COMMENT '区县' ,
    detail VARCHAR(128) NOT NULL   COMMENT '详细地址' ,
    extand VARCHAR(128)    COMMENT '扩展字段' ,
    is_default INT    COMMENT '是否默认地址 1:是  0:否' ,
    created_time DATETIME NOT NULL   COMMENT '创建时间' ,
    updated_time DATETIME NOT NULL   COMMENT '更新时间' ,
    PRIMARY KEY (id)
) COMMENT = '用户地址表 ';;

ALTER TABLE user_address COMMENT '用户地址表';;
DROP TABLE items;;/*SkipError*/
CREATE TABLE items(
    id VARCHAR(64) NOT NULL   COMMENT '商品主键id' ,
    item_name VARCHAR(32) NOT NULL   COMMENT '商品名称 商品名称' ,
    cat_id INT NOT NULL   COMMENT '分类外键id 分类id' ,
    root_cat_id INT NOT NULL   COMMENT '一级分类外键id 一级分类id，用于优化查询' ,
    sell_counts INT NOT NULL   COMMENT '累计销售 累计销售' ,
    on_off_status INT NOT NULL   COMMENT '上下架状态 上下架状态,1:上架 2:下架' ,
    content TEXT NOT NULL   COMMENT '商品内容 商品内容' ,
    created_time DATETIME NOT NULL   COMMENT '创建时间' ,
    updated_time DATETIME NOT NULL   COMMENT '更新时间' ,
    PRIMARY KEY (id)
) COMMENT = '商品表 商品信息相关表：分类表，商品图片表，商品规格表，商品参数表';;

ALTER TABLE items COMMENT '商品表';;
DROP TABLE items_img;;/*SkipError*/
CREATE TABLE items_img(
    id VARCHAR(64) NOT NULL   COMMENT '图片主键' ,
    item_id VARCHAR(64) NOT NULL   COMMENT '商品外键id 商品外键id' ,
    url VARCHAR(128) NOT NULL   COMMENT '图片地址 图片地址' ,
    sort INT NOT NULL   COMMENT '顺序 图片顺序，从小到大' ,
    is_main INT NOT NULL   COMMENT '是否主图 是否主图，1：是，0：否' ,
    created_time DATETIME NOT NULL   COMMENT '创建时间' ,
    updated_time DATETIME NOT NULL   COMMENT '更新时间' ,
    PRIMARY KEY (id)
) COMMENT = '商品图片 ';;

ALTER TABLE items_img COMMENT '商品图片';;
DROP TABLE items_spec;;/*SkipError*/
CREATE TABLE items_spec(
    id VARCHAR(64) NOT NULL   COMMENT '商品规格id' ,
    item_id VARCHAR(64) NOT NULL   COMMENT '商品外键id' ,
    name VARCHAR(32) NOT NULL   COMMENT '规格名称' ,
    stock INT NOT NULL   COMMENT '库存' ,
    discounts DECIMAL(4,2) NOT NULL   COMMENT '折扣力度' ,
    price_discount INT NOT NULL   COMMENT '优惠价' ,
    price_normal INT NOT NULL   COMMENT '原价' ,
    created_time DATETIME NOT NULL   COMMENT '创建时间' ,
    updated_time DATETIME NOT NULL   COMMENT '更新时间' ,
    PRIMARY KEY (id)
) COMMENT = '商品规格 每一件商品都有不同的规格，不同的规格又有不同的价格和优惠力度，规格表为此设计';;

ALTER TABLE items_spec COMMENT '商品规格';;
DROP TABLE items_param;;/*SkipError*/
CREATE TABLE items_param(
    id VARCHAR(64) NOT NULL   COMMENT '商品参数id' ,
    item_id VARCHAR(32) NOT NULL   COMMENT '商品外键id' ,
    produc_place VARCHAR(32) NOT NULL   COMMENT '产地 产地，例：中国江苏' ,
    foot_period VARCHAR(32) NOT NULL   COMMENT '保质期 保质期，例：180天' ,
    brand VARCHAR(32) NOT NULL   COMMENT '品牌名 品牌名，例：三只大灰狼' ,
    factory_name VARCHAR(32) NOT NULL   COMMENT '生产厂名 生产厂名，例：大灰狼工厂' ,
    factory_address VARCHAR(32) NOT NULL   COMMENT '生产厂址 生产厂址，例：大灰狼生产基地' ,
    packaging_method VARCHAR(32) NOT NULL   COMMENT '包装方式 包装方式，例：袋装' ,
    weight VARCHAR(32) NOT NULL   COMMENT '规格重量 规格重量，例：35g' ,
    storage_method VARCHAR(32) NOT NULL   COMMENT '存储方法 存储方法，例：常温5~25°' ,
    eat_method VARCHAR(32) NOT NULL   COMMENT '食用方式 食用方式，例：开袋即食' ,
    created_time DATETIME NOT NULL   COMMENT '创建时间' ,
    updated_time DATETIME NOT NULL   COMMENT '更新时间' ,
    PRIMARY KEY (id)
) COMMENT = '商品参数 ';;

ALTER TABLE items_param COMMENT '商品参数';;
DROP TABLE items_comments;;/*SkipError*/
CREATE TABLE items_comments(
    id VARCHAR(64) NOT NULL   COMMENT 'id主键' ,
    user_id VARCHAR(64)    COMMENT '用户id 用户名须脱敏' ,
    item_id VARCHAR(64) NOT NULL   COMMENT '商品id' ,
    item_name VARCHAR(64)    COMMENT '商品名称' ,
    item_spec_id VARCHAR(64)    COMMENT '商品规格id 可为空' ,
    sepc_name VARCHAR(32)    COMMENT '规格名称 可为空' ,
    comment_level INT NOT NULL   COMMENT '评价等级 1：好评 2：中评 3：差评' ,
    content VARCHAR(128) NOT NULL   COMMENT '评价内容' ,
    created_time DATETIME    COMMENT '创建时间' ,
    updated_time DATETIME    COMMENT '更新时间' ,
    PRIMARY KEY (id)
) COMMENT = '商品评价表 ';;

ALTER TABLE items_comments COMMENT '商品评价表';;
DROP TABLE orders;;/*SkipError*/
CREATE TABLE orders(
    id VARCHAR(64) NOT NULL   COMMENT '订单主键 同时也是订单编号' ,
    user_id VARCHAR(64) NOT NULL   COMMENT '用户id' ,
    receiver_name VARCHAR(32) NOT NULL   COMMENT '收货人快照' ,
    receiver_mobile VARCHAR(32) NOT NULL   COMMENT '收货人手机号快照' ,
    receiver_address VARCHAR(128) NOT NULL   COMMENT '收货地址快照' ,
    total_amount INT NOT NULL   COMMENT '订单总价格' ,
    real_pay_amount INT NOT NULL   COMMENT '实际支付总价格' ,
    post_amount INT NOT NULL  DEFAULT 0 COMMENT '邮费 默认可以为零，代表包邮' ,
    pay_method INT NOT NULL   COMMENT '支付方式 1:微信 2:支付宝' ,
    left_msg VARCHAR(128)    COMMENT '买家留言' ,
    extand VARCHAR(32)    COMMENT '扩展字段' ,
    is_comment INT NOT NULL   COMMENT '买家是否评价 1：已评价，0：未评价' ,
    is_delete INT NOT NULL  DEFAULT 0 COMMENT '逻辑删除状态 1: 删除 0:未删除' ,
    created_time DATETIME NOT NULL   COMMENT '创建时间（成交时间）' ,
    updated_time DATETIME NOT NULL   COMMENT '更新时间' ,
    PRIMARY KEY (id)
) COMMENT = '订单表 ';;

ALTER TABLE orders COMMENT '订单表';;
DROP TABLE order_items;;/*SkipError*/
CREATE TABLE order_items(
    id VARCHAR(64) NOT NULL   COMMENT '主键id' ,
    order_id VARCHAR(64) NOT NULL   COMMENT '归属订单id' ,
    item_id VARCHAR(64) NOT NULL   COMMENT '商品id' ,
    item_img VARCHAR(128) NOT NULL   COMMENT '商品图片' ,
    item_name VARCHAR(32) NOT NULL   COMMENT '商品名称' ,
    item_spec_id VARCHAR(32) NOT NULL   COMMENT '规格id' ,
    item_spec_name VARCHAR(32) NOT NULL   COMMENT '规格名称' ,
    price INT NOT NULL   COMMENT '成交价格' ,
    buy_counts INT NOT NULL   COMMENT '购买数量' ,
    PRIMARY KEY (id)
) COMMENT = '订单商品关联表 ';;

ALTER TABLE order_items COMMENT '订单商品关联表';;
DROP TABLE order_status;;/*SkipError*/
CREATE TABLE order_status(
    order_id VARCHAR(64) NOT NULL   COMMENT '订单ID 对应订单表的主键id' ,
    order_status INT NOT NULL   COMMENT '订单状态' ,
    created_time DATETIME    COMMENT '订单创建时间 对应[10:待付款]状态' ,
    pay_time DATETIME    COMMENT '支付成功时间 对应[20:已付款，待发货]状态' ,
    deliver_time DATETIME    COMMENT '发货时间 对应[30：已发货，待收货]状态' ,
    success_time DATETIME    COMMENT '交易成功时间 对应[40：交易成功]状态' ,
    close_time DATETIME    COMMENT '交易关闭时间 对应[50：交易关闭]状态' ,
    comment_time DATETIME    COMMENT '留言时间 用户在交易成功后的留言时间' ,
    PRIMARY KEY (order_id)
) COMMENT = '订单状态表 订单的每个状态更改都需要进行记录
10：待付款  20：已付款，待发货  30：已发货，待收货（7天自动确认）  40：交易成功（此时可以评价）50：交易关闭（待付款时，用户取消 或 长时间未付款，系统识别后自动关闭）
退货/退货，此分支流程不做，所以不加入';;

ALTER TABLE order_status COMMENT '订单状态表';;
