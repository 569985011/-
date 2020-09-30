'''一段代码理解<datetime>库    参考 https://docs.python.org/zh-cn/3/library/datetime.html
oatetime库包含子类 ----datetime 日期和时间的结合
                   ----date     简单型日期
                   ----time     简单型时间
                   ----timedelta 时间间隔，用于运算  （其他类对象均不可修改，不可运算）
                   ----tzinfo   描述时区的抽象基类----timezone 表示相对世界标准时间UTC的偏移量
'''
import datetime


def main():
    d()    '4.datetime子类'
    
    a()    '1.自定义strptime()读strftime()写,适用于datetime,date,time子类'
    
    b()    '2.日期时间 运算  或者说是 timedelta子类'

    c()    '3.date子类'


def a():    '1.自定义strptime()读strftime()写

    'strptime()用于将合规字符串转换为datetime对象'
    Input = "2019-Mar-18%14:03:15.123456 GMT"
    Output = datetime.datetime.strptime(Input, "%Y-%b-%d%%%H:%M:%S.%f %Z")   

    #strftime将date对象time对象datetime对象转换为指定格式字符串输出    
    print(datetime.datetime.strftime(Output, "%Y-%m-%d %I:%M:%S%P"))
    #____2019-03-18 02:03:15PM
'''
     常用的格式化指令：%a星期几的缩写（比如：Sun,Mon...）
                       %A星期几的完成名称（比如：Sunday,Monday...)
                       %w以十进制现实的工作日，其中0表示周日，6表示周六
                       %d以十进制数显示的月份中的一天（如：01,...31）
                       %b月份的的缩写（比如：Jan,Feb...)
                       %B月份的全称（比如：January,February...)
                       %m以十进制数显示的月份(如：01，...12)
                       %y不带世纪的十进制年份（如：00,...99）
                       %Y带世纪的湿巾纸年份（如:0001,2020,9999)
                       %H   24小时的时钟
                       %I   12小时的时钟  %p 标识上下午（如 AM,pm）
                       %M   十进制的分钟
                       %S   十进制的秒钟
                           %f   十进制的毫秒（如:000000,999999）
                           %z  UTC偏移量格式为±HHMM[SS[.ffffff]](如:+0000,-063415,+030712.345216)
                           %Z   时区名称
                           %j   一年中的第几天
                           %U   一年的第几周（周日作为每周第一天，新年第一个周日前视为第0周）
                           %W   一年的第几周（周一视为每周第一天，新年第一个周一前视为第0周）
                           %c系统日期和时间表示 %x系统日期表示 %X系统时间表示  使用 locale.getlocale() 可确定当前区域设置的编码格式）。
                           %%   字面的'%'字符
'''                           
def b():    '2.日期时间 运算    或者说是   timedelta对象'
    delta = timedelta(
        days=50,
        seconds=27,
        microseconds=10,
        milliseconds=29000,
        minutes=5,
        hours=8,
        weeks=2
        )    
    #____delta====datetime.timedelta(days=64, seconds=29156, microseconds=10)
    '''
    上述所有参数默认为零选填，但对象只会转换成days,seconds,microseconds储存在内部'
    换算规则如下：  1毫秒转换为1000微秒
                    1分钟60秒  1小时3600秒  1星期7天
    day有效范围±999999999，seconds有效范围0至86399，microseconds有效范围0至999999，
    所以当传入参数有负数时会被自动规范化
    timedelta.total_seconds()可以直接返回时间间隔包含了多少秒。
    对于其他单位可以直接用除法(如：delta/timedelta(seconds=1))也可以得到总秒数    
    '''
    delta=timedelta(hours=-5)
    #____delta====datetime.timedelta(days=-1, seconds=68400)
    print (delta)
    #____-1 day,19:00:00  
    '''
    str(timedelta对象)会得到一个[D day[s],][H]H:MM:SS[.UUUUUU]的字符串
    timedelta对象  可以相互间进行+-*/% 整除 取绝对值 取相反数等运算
    timedelta对象 可以==或!=或>或<比较，返回一个bool对象，
    '''
def c():    'date对象'
     ToDay = datetime.date.today()   '等价于date.fromtimestamp(time.time())'
     A_Day = datetime.date.fromtimestamp(time.time())'返回对应POSIX时间戳的date对象'
     
     B_Day = datetime.date(2020,03,05)
     C_Day = datetime.date.fromordinal(737489)'返回对应ordinal序号的date对象，其中公元1年1月1日的序号为1'
     D_Day = datetime.date.fromisoformat("2020-03-05")'返回对应YYYY-MM-DD字符串的date对象'
     G_Day = datetime.date.fromisocalendar(2020,10,4)'返回对应YYYY-第几周-第几天字符串的date对象'
'''
    以上为date对象构造方法，date对象可用的属性包括.min(最小日期),.max(最大日期)
    .resolution(两个日期对象的最小间隔).year(年份).month(月份).day(几号).replace(自我复制)
    .toordinal(返回格列高利历序号).weekday(周几？0表示周一).isoweekday(周几？7表示周日)
    .isocalendar(返回三元元祖[ISOyear,ISOweeknumber,ISOweekday])ISO历法每周始于周一，新年第一个周四视为第一周
    例如2004年第一天是周四，所以ISO历法第一周开始于2013年12月29日星期一
    .isoformat(返回YYYY-MM-DD格式的字符串)  等价于str(B_Day)
    .strftime(format)返回自定义格式字符串    等价于format(format)
    .timetuple()返回time.struct_time对象，自行补充0时0分秒且DST=-1
    .ctime()返回包含0时0分0秒的字符串
    
'''
def d():    'datetime对象'
    ToDay = datetime.datetime.today() '本地当前日期时间'
    T2Day = datetime.datetime.now()   '本地当前日期时间'
    T3Day = datetime.datetime.utcnow() 'UTC当前日期时间'
    T4Day = datetime.datetime.fromtimestamp(time.time())'返回对应POSIX时间戳的datetime对象'
    T5Day = datetime.datetime.fromutctimestamp(time.time())''
    
     B_Day = datetime.datetime(2020,03,05,0,0,0)'年月日为必须参数，其他默认0'
     C_Day = datetime.datetime.fromordinal(737489)'根据对应ordinal序号的date，补齐0时0分0秒，返回datetime对象'
     D_Day = datetime.datetime.fromisoformat("2020-03-05 00:00:00")
     G_Day = datetime.datetime.fromisocalendar(2020,10,4)'自动补齐0时0分0秒，构造datetime对象'
#     E_Day = datetime.datetime.combine(date对象,time对象,[tzinfo对象]）
'''
    区别于date对象,datetime对象可用的属性还包括:.timestamp()
'''
