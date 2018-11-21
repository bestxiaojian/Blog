# NLP核心技术与算法

## 一、中文分词技术

中文分词的主要困难在于歧义，比如经典的例子：”结婚的和尚未结婚的“，人来分词都是有歧义的，机器更难处理。

中文分词主要归纳为如下方法：

- 规则分词
- 统计分词
- 规则+统计分词

### 规则分词

按照匹配的切分方式：

- 正向最大匹配法
- 逆向最大匹配法
- 双向最大匹配法

**正向最大匹配算法示例代码：**

```python
class MM(object):
    def __init__(self):
        self.window_size = 3
    def cut(self,text):
        result = []
        index = 0
        text_length = len(text)
        dic = ["研究","研究生","生命","命","的","起源"]
        while text_length > index:
            for size in range(self.window_size+index,index,-1):
                piece = text[index:size]
                if piece in dic:
                    index = size - 1 #此次切分最后一个字符的位置
                    break
            result.append(piece+"/")
            index = index + 1
        print(result)
if __name__ ==  "__main__":
    text = "研究生命的起源"
    tokenizer = MM()
    tokenizer.cut(text)
```

**逆向最大匹配算法：**

```python
#逆向最大匹配算法
# -*- coding:utf-8 -*-
class RMM(object):
    def __init__(self):
        self.window_size = 3
    def cut(self,text):
        result = []
        index = len(text)
        dic = ["研究","研究生","生命","命","的","起源"]
        while index > 0:
            for size in range(index-self.window_size,index):
                piece = text[size:index]
                if piece in dic:
                    index = size + 1
                    break
            result.append(piece+"/")
            index = index - 1
        result.reverse()
        print(result)

if __name__ == "__main__":
    text = "研究生命的起源"
    tokenizer = RMM()
    tokenizer.cut(text)
```

**双向最大匹配法：**

- 如果正反向分词结果数量不同，则取分词数量较少的那个

- 如果分词结果词数相同：

  1.分词结果相同的话：说明没有歧义，可返回任意一个

  2.分词结果不同：返回其中单字较少的那个

### 统计分词



























































