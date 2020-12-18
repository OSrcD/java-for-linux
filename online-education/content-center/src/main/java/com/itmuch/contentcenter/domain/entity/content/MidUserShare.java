package com.itmuch.contentcenter.domain.entity.content;

import javax.persistence.*;

import lombok.*;

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@Table(name = "mid_user_share")
public class MidUserShare {
    @Id
    @GeneratedValue(generator = "JDBC")
    private Integer id;

    /**
     * share.id
     */
    @Column(name = "share_id")
    private Integer shareId;

    /**
     * user.id
     */
    @Column(name = "user_id")
    private Integer userId;
}