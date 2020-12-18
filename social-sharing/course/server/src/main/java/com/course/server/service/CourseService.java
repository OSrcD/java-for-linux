package com.course.server.service;

import com.course.server.domain.Course;
import com.course.server.domain.CourseExample;
import com.course.server.dto.CourseDto;
import com.course.server.dto.PageDto;
import com.course.server.mapper.CourseMapper;
import com.course.server.util.CopyUtil;
import com.course.server.util.UuidUtil;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;
import javax.annotation.Resource;
import java.util.List;
import java.util.Date;

@Service
public class CourseService {

    @Resource
    private CourseMapper courseMapper;

    /**
     * 列表查询
     * @param pageDto
     */
    public void list(PageDto pageDto){
        PageHelper.startPage(pageDto.getPage(),pageDto.getSize());
        CourseExample courseExample = new CourseExample();
        courseExample.setOrderByClause("sort asc");

        List<Course> courseList = this.courseMapper.selectByExample(courseExample);
        PageInfo<Course> pageInfo = new PageInfo<>(courseList);

        pageDto.setTotal(pageInfo.getTotal());



        List<CourseDto> courseDtoList = CopyUtil.copyList(courseList,CourseDto.class);
        pageDto.setList(courseDtoList);

    }

    /**
     * 保存，id有值时更新，无值时新增
     * @param courseDto
     */
    public void save(CourseDto courseDto){
        Course course = CopyUtil.copy(courseDto,Course.class);
        if(StringUtils.isEmpty(courseDto.getId())){
            this.insert(course);
        }else{
            this.update(course);
        }

    }

    /**
     * 新增
     * @param course
     */
    public void insert(Course course){
        Date now = new Date();
        course.setCreatedAt(now);
        course.setUpdatedAt(now);
        course.setId(UuidUtil.getShortUuid());
        this.courseMapper.insert(course);
    }

    /**
     * 更新
     * @param course
     */
    private void update(Course course){
        course.setUpdatedAt(new Date());
        this.courseMapper.updateByPrimaryKey(course);
    }

    /**
     * 删除
     * @param id
     */
    public void delete(String id) {

        courseMapper.deleteByPrimaryKey(id);


    }
}
