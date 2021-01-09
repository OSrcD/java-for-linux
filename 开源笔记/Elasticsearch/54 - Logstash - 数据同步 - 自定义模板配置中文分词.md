![](https://tcs.teambition.net/storage/3121bb336834099d0bf4af47015c8c315178?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYjMzNjgzNDA5OWQwYmY0YWY0NzAxNWM4YzMxNTE3OCJ9.0nW0syvD0QEyApWnSUh-t6S3dgkitWCXkDQUZIc33ts&download=2020-09-17%20175833.png "")

## 安装中文分词插件 可看 17 - Elasticsearch - 建立 ik 中文分词器 



![](https://tcs.teambition.net/storage/312107a8e0004ff8d242c1a4f1eb4aa01790?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwN2E4ZTAwMDRmZjhkMjQyYzFhNGYxZWI0YWEwMTc5MCJ9.90R0Q2KdOJGN0RNnkGR5OA49pTvRUWpz9iykQnB3z-Y&download=image.png "")

![](https://tcs.teambition.net/storage/3121cc266daf7e01204aff241263540e40ed?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjYzI2NmRhZjdlMDEyMDRhZmYyNDEyNjM1NDBlNDBlZCJ9.et6I_f9a_2x9u8T35v9HRqcq12gaBieggIIfdubPdEc&download=image.png "")

```text
http://192.168.245.151:9200/_template/logstash

```

```json
{
    "logstash": {
        "order": 0,
        "version": 60001,
        "index_patterns": [
            "logstash-*"
        ],
        "settings": {
            "index": {
                "refresh_interval": "5s"
            }
        },
        "mappings": {
            "_default_": {
                "dynamic_templates": [
                    {
                        "message_field": {
                            "path_match": "message",
                            "match_mapping_type": "string",
                            "mapping": {
                                "type": "text",
                                "norms": false
                            }
                        }
                    },
                    {
                        "string_fields": {
                            "match": "*",
                            "match_mapping_type": "string",
                            "mapping": {
                                "type": "text",
                                "norms": false,
                                "fields": {
                                    "keyword": {
                                        "type": "keyword",
                                        "ignore_above": 256
                                    }
                                }
                            }
                        }
                    }
                ],
                "properties": {
                    "@timestamp": {
                        "type": "date"
                    },
                    "@version": {
                        "type": "keyword"
                    },
                    "geoip": {
                        "dynamic": true,
                        "properties": {
                            "ip": {
                                "type": "ip"
                            },
                            "location": {
                                "type": "geo_point"
                            },
                            "latitude": {
                                "type": "half_float"
                            },
                            "longitude": {
                                "type": "half_float"
                            }
                        }
                    }
                }
            }
        },
        "aliases": {}
    }
}

```

![](https://tcs.teambition.net/storage/31214873ede3062086fe8b3e6d0e426ad307?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ODczZWRlMzA2MjA4NmZlOGIzZTZkMGU0MjZhZDMwNyJ9.gITzQLAHS2kLGANkeovZplh9RDwewcaOxFGMRN8_Ycs&download=image.png "")

## 这个就是在同步的时候为 我们去创建映射

## 增加IK分词器

![](https://tcs.teambition.net/storage/3121182e9590b2568d7a003257421128b1cf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExODJlOTU5MGIyNTY4ZDdhMDAzMjU3NDIxMTI4YjFjZiJ9.ASowkImH-rKIjElSUgVjTGUTmxw4Sb_YkY_Jy_RdF2o&download=image.png "")

## 这个是模板标识

![](https://tcs.teambition.net/storage/3121b15aeeacc4d1f78eb93cf4a1b505cc83?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMTVhZWVhY2M0ZDFmNzhlYjkzY2Y0YTFiNTA1Y2M4MyJ9.logQX1UnAfXTRmkUl6oABGL4u5r_q1BAllA9isF81wc&download=image.png "")

## 删除掉

![](https://tcs.teambition.net/storage/31211e0cf35a70f7c6120a8b844daf94af33?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZTBjZjM1YTcwZjdjNjEyMGE4Yjg0NGRhZjk0YWYzMyJ9.RxCa1pzCtiK_n3uQXHEc_-ChLbAmKozAGMEjPCNN8vs&download=image.png "")

![](https://tcs.teambition.net/storage/312175fdbc34db2b0963a947532a8af7ca21?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NWZkYmMzNGRiMmIwOTYzYTk0NzUzMmE4YWY3Y2EyMSJ9.Gv-8vv-e4nnmsaJZNyntYkPhJA99Cs7Jdm9NwHDVEfQ&download=image.png "")

![](https://tcs.teambition.net/storage/312118c0f516672e8eaa7ed3c7d723640062?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExOGMwZjUxNjY3MmU4ZWFhN2VkM2M3ZDcyMzY0MDA2MiJ9.Tl65j-nfz4blGj5f-Rqn5WNO6jAZfBFOwatAJFS6NQE&download=image.png "")

## "order": 0 顺序

![](https://tcs.teambition.net/storage/31219d4ded277c01834f9b853df0bbbac7bc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5ZDRkZWQyNzdjMDE4MzRmOWI4NTNkZjBiYmJhYzdiYyJ9.OWbLpvaff2HeV-1SjUaTqcftYU4QvVqNu5lUJh7pSwY&download=image.png "")

```json
{
  "order": 0,
  "version": 1,
  "index_patterns": ["*"],
  "settings": {
    "index": {
      "refresh_interval": "5s"
    }
  },
  "mappings": {
    "_default_": {
      "dynamic_templates": [
        {
          "message_field": {
            "path_match": "message",
            "match_mapping_type": "string",
            "mapping": {
              "type": "text",
              "norms": false
            }
          }
        },
        {
          "string_fields": {
            "match": "*",
            "match_mapping_type": "string",
            "mapping": {
              "type": "text",
              "norms": false,
              "analyzer": "ik_max_word",
              "fields": {
                "keyword": {
                  "type": "keyword",
                  "ignore_above": 256
                }
              }
            }
          }
        }
      ],
      "properties": {
        "@timestamp": {
          "type": "date"
        },
        "@version": {
          "type": "keyword"
        },
        "geoip": {
          "dynamic": true,
          "properties": {
            "ip": {
              "type": "ip"
            },
            "location": {
              "type": "geo_point"
            },
            "latitude": {
              "type": "half_float"
            },
            "longitude": {
              "type": "half_float"
            }
          }
        }
      }
    }
  },
  "aliases": {}
}


```

![](https://tcs.teambition.net/storage/3121162a3f7aeb4b50d7be13ab375233dc61?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNjJhM2Y3YWViNGI1MGQ3YmUxM2FiMzc1MjMzZGM2MSJ9.S1JId-8NbLbgRj3lyeahvBetz7ZYZJrGl4SytdfZToI&download=image.png "")

## 复制进来

![](https://tcs.teambition.net/storage/312158de22212214e306363530bf9a2f55bb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1OGRlMjIyMTIyMTRlMzA2MzYzNTMwYmY5YTJmNTViYiJ9.4Q-3fY2qYJKXkVv4BPA1ksNNJX9YfB1mHymd_3dxsgs&download=image.png "")

```text
# 定义模板名称
        template_name => "myik"
        # 模板所在位置
        template => "/usr/local/logstash-6.4.3/sync/logstash-ik.json"
        # 重写模板
        template_overwrite => true
        # 默认为true,false关闭logstash自动管理模板功能,如果自定义模板,则设置为false
        manage_template => false

```

## 创建 新的索引

![](https://tcs.teambition.net/storage/3121d3d376ba8ee5ddf2ad589ceff348d215?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkM2QzNzZiYThlZTVkZGYyYWQ1ODljZWZmMzQ4ZDIxNSJ9.G3wBofmdBCMm5JNDT5T66GGGNM4den15mR7hvjx7jmU&download=image.png "")

![](https://tcs.teambition.net/storage/312153fb766ce86327b1365ebc2d3ba11f71?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1M2ZiNzY2Y2U4NjMyN2IxMzY1ZWJjMmQzYmExMWY3MSJ9.-AwCptAWOPB0UHOteahHFqTH-YdO8pJGghlrt0h3-LU&download=image.png "")

## 去做一个同步

![](https://tcs.teambition.net/storage/312121a1f936ce4db361edf70f6f17cd8bad?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyMWExZjkzNmNlNGRiMzYxZWRmNzBmNmYxN2NkOGJhZCJ9.iFEDV28IdCZgq1o1yP2zIkqCAH2O38ImV94n31-hkbo&download=image.png "")

## 把数据库时间调比logstash的大

![](https://tcs.teambition.net/storage/312111a3fd56d9d14d5672ee8145bb9b7b93?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMWEzZmQ1NmQ5ZDE0ZDU2NzJlZTgxNDViYjliN2I5MyJ9.VadVQxPo0k_bCL10CReP_u_iGlbzM4DwYcBdnSy1Nrw&download=image.png "")

```sql
UPDATE items SET updated_time = 
  DATE_ADD(updated_time,INTERVAL 6 MONTH)

```

![](https://tcs.teambition.net/storage/31211e522655f250c875dff7e266ef5e6355?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZTUyMjY1NWYyNTBjODc1ZGZmN2UyNjZlZjVlNjM1NSJ9.VBegz1exyf9yAeS2HTFrQz68TK_wC-Y5cfkXb_XEGmE&download=image.png "")

![](https://tcs.teambition.net/storage/31210d20c28f8beacc835cb6a223192a9616?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwZDIwYzI4ZjhiZWFjYzgzNWNiNmEyMjMxOTJhOTYxNiJ9.TwVVXoPctm8znUyM9vyPokCuaa7a_Q7jZaaoL6q_5WQ&download=image.png "")

![](https://tcs.teambition.net/storage/31219cdcff445bad912576acb801d7b8bfb1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5Y2RjZmY0NDViYWQ5MTI1NzZhY2I4MDFkN2I4YmZiMSJ9.Gpm6HyIi7kHwdpOF4MqArEkvtvsgnbC76VrHAkxTU-c&download=image.png "")



## 退出之前的

![](https://tcs.teambition.net/storage/31219a90ba7ea153ec0b406d79879757d74c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YTkwYmE3ZWExNTNlYzBiNDA2ZDc5ODc5NzU3ZDc0YyJ9.YXnof3bNL1v3t4w40vhSXlvfT1Qu4lIvjY_g21YmoNc&download=image.png "")

## 再重新启动

![](https://tcs.teambition.net/storage/3121ee31bcf1f7363a7afa94132ee8c893e6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZTMxYmNmMWY3MzYzYTdhZmE5NDEzMmVlOGM4OTNlNiJ9.m0e8kwTwkr3NLIZ5GvymNjGco-Dwlux3_xEABCz53ek&download=image.png "")

![](https://tcs.teambition.net/storage/31218e84c561abb6958334b592b5dbd495a5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4ZTg0YzU2MWFiYjY5NTgzMzRiNTkyYjVkYmQ0OTVhNSJ9.m0qQEViNohRZUvLPTqfw3hhbAAlONX-dt_tF_fwYNKc&download=image.png "")

## 同步失效

![](https://tcs.teambition.net/storage/3121cfaa2c4e7a1f6be9bcbe3af8995dd4c5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZmFhMmM0ZTdhMWY2YmU5YmNiZTNhZjg5OTVkZDRjNSJ9.2j7arOBwkhborsWbg9noY2AscMDbN0ZVh6Rfd_bQdLE&download=image.png "")

## 手动创建索引

```json
{
  "mappings": {
    "_doc": {
      "properties": {
        "imgUrl": {
          "analyzer": "ik_max_word",
          "type": "text",
          "fields": {
            "keyword": {
              "ignore_above": 256,
              "type": "keyword"
            }
          }
        },
        "itemId": {
          "analyzer": "ik_max_word",
          "type": "text",
          "fields": {
            "keyword": {
              "ignore_above": 256,
              "type": "keyword"
            }
          }
        },
        "updated_time": {
          "type": "date"
        },
        "itemName": {
          "analyzer": "ik_max_word",
          "type": "text",
          "fields": {
            "keyword": {
              "ignore_above": 256,
              "type": "keyword"
            }
          }
        },
        "@timestamp": {
          "type": "date"
        },
        "sellCounts": {
          "type": "long"
        },
        "price": {
          "type": "long"
        },
        "@version": {
          "analyzer": "ik_max_word",
          "type": "text",
          "fields": {
            "keyword": {
              "ignore_above": 256,
              "type": "keyword"
            }
          }
        },
        "type": {
          "analyzer": "ik_max_word",
          "type": "text",
          "fields": {
            "keyword": {
              "ignore_above": 256,
              "type": "keyword"
            }
          }
        }
      }
    }
  }
}

```

![](https://tcs.teambition.net/storage/312125b250371b391b818dc98f23ee0eefc7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNWIyNTAzNzFiMzkxYjgxOGRjOThmMjNlZTBlZWZjNyJ9.97F-2uLQKHV7aRUF_3zQNGU-r92qdcgFjOu1HNHtTPQ&download=image.png "")

![](https://tcs.teambition.net/storage/31211db954305d96a4d3955ac97047d43047?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZGI5NTQzMDVkOTZhNGQzOTU1YWM5NzA0N2Q0MzA0NyJ9.XQSfXY_zOzX3C4f8VRhAaIiBgwtOctt93l_S8xKgA-s&download=image.png "")

![](https://tcs.teambition.net/storage/31217e7e263d4bbb9f74ede252a7465d6a47?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZTdlMjYzZDRiYmI5Zjc0ZWRlMjUyYTc0NjVkNmE0NyJ9.MarkpmTx6Bbgbdpx0aeNAnYaBHan48T7JGcTEn2MD1g&download=image.png "")

![](https://tcs.teambition.net/storage/312125e331fa12c438cf46ef8b0c67fa1950?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNWUzMzFmYTEyYzQzOGNmNDZlZjhiMGM2N2ZhMTk1MCJ9.fATbK6g2WhgqpMmQZi_G2HEjfge8eoP7tHTAXvOx6gE&download=image.png "")



开源笔记

可 Pull Requests 协作写开源笔记

gitee

[https://gitee.com/opendevel/java-for-linux](https://gitee.com/opendevel/java-for-linux)

github

[https://github.com/OSrcD/java-for-linux](https://github.com/OSrcD/java-for-linux)

teambition

[https://tburl.in/0jDNvpbK](https://tburl.in/0jDNvpbK)

开源视频

bilibili

[https://space.bilibili.com/77266754](https://space.bilibili.com/77266754)

开源博客

oschina

[https://my.oschina.net/u/4675154](https://my.oschina.net/u/4675154)

csdn

[https://blog.csdn.net/OpenDevel](https://blog.csdn.net/OpenDevel)

开源项目

gitee

[https://gitee.com/opendevel](https://gitee.com/opendevel)

github

[https://github.com/OSrcD](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM4MywiaWF0IjoxNjEwMjA4NTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.LOpvRgSV26orW_2F96dhE2gzun6MBd2aUM6K00-LyBc&download=image.png "")

