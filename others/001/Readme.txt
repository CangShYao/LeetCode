余补法

其实代码可以写成两个for
第一个for是用来处理原始数据，得到所有数据的「余数数组(最好用map存起来，key：number，value：position)」
第二个for在便利每一个数时，余数数组.count(number)
    如果在余数数组中存在这样的值，那么count的结果就是1
    那么返回当前的position，以及「余数数组[number](余数数组的方括号运算得到就是本身的位置)」

如果写成一个for改怎么写呢
在循环中直接判断 余数数组.count(number)
问题来了，number不存在map中怎么返回什么。答案：返回0