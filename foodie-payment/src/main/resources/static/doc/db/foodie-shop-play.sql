DROP TABLE IF EXISTS `pays`;
CREATE TABLE `pays`(
                       `id` VARCHAR(64) NOT NULL COMMENT '订单主键',
                       `merchant_order_id` VARCHAR(64) NOT NULL COMMENT '商户订单号',
                       `merchant_user_id` VARCHAR(64) NOT NULL COMMENT '商户方的发起用户的用户主键id',
                       `amount` INT(11) NOT NULL  COMMENT '实际支付的总金额（包含商户所支付的订单费邮费总额）',
                       `pay_method` INT(11) NOT NULL COMMENT '支付方式',
                       `pay_status` INT(11) NOT NULL COMMENT '支付状态；10：未支付 20：已支付 30：支付失败 40：已退款',
                       `come_from` VARCHAR(128) NOT NULL COMMENT '从哪一端来的，比如从天天吃货这门实战过来的',
                       `return_url` VARCHAR(255) NOT NULL COMMENT '支付成功后的通知地址，这个是开发者哪一端，不是第三方支付通知的地址',
                       `is_delete` INT(11) NOT NULL COMMENT '逻辑删除状态；1：删除 0：未删除',
                       `created_time` datetime NOT NULL COMMENT '创建时间（成交时间）',
                       PRIMARY KEY(`id`)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='支付表';

ALTER TABLE pays COMMENT '支付表';;