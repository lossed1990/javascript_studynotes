/**
 * @brief 第三章 类型、值和变量
 */
class Chapter3
{
public:
    /**
	 * @brief 前言
	 *
	 * @note ①js的数据类型分为两类：原始类型和对象类型；
	 * @note ②原始类型包括：数字、字符串、布尔值；（两个特殊的原始值：null undefined）
	 * @note ③除原始类型之外的就是对象；
	 * @note ④几个特殊的对象：全局对象（global object），数组（array有序集合），函数（函数是具有与他相关联的可执行代码的对象，和数组一样，函数的行为特征和其他对象都不一样） 
	 * @note ⑤如果函数用来初始化（使用new运算符）一个新建的对象，我们称之为构造函数。每个构造函数定义了一类对象。
	 * @note ⑥js语言核心定义的几个重要类：Array（数组）、Function（函数）、Date（日期）、RegExp（正则）、Error（错误）；
	 * @note ⑦js是一种面向对象的语言。不严格的讲，我们不要全局的定义函数去操作不同类型的值，数据类型本身可以定义方法来使用值；
	 * @code
           //例如，要对数组中的元素进行排序，不必要将a传入sort()函数，而是调用a的一个方法sort()
		   a.sort(); //sort(a)的面向对象版本 
	 * @endcode
	 * @note ⑧从技术上讲，只有js对象才能拥有方法，然而，数字、字符串、布尔值也可以拥有自己的方法。在js中只有null和undefined是无法拥有方法的值。
	 * @note ⑨不在任何函数内声明的变量称作全局变量，它在js程序中的任何地方可见，在函数内声明的变量具有函数作用域，尽在函数内可见。
	 */
	void knowledge_point01;

    /**
	 * @brief 3.1数字
	 *
	 * @note ①js不区分整数值和浮点数值，在js中所有数字均用浮点数值表示。表示范围（-2^53 ~ 2^53）；
	 * @note ②最好不要使用以0为前缀的8进制整形直接量；
	 * @note ③js中的算术运算符在溢出、下溢或者被0整除时不会报错，结果为一个特殊的无穷大值，用Infinity表示（负无穷大：-Infinity）
	 * @note ④特例：零除以零是无意义的，其也返回一个非数字值，用NaN表示；无穷大除以无穷大、给任意负数开方、算术运算符与不是数字或无法转换成数字的操作数一起使用时，都将返回NaN；
	 * @note ⑤Infinity（正无穷大） NaN（非数字值）
	 * @note ⑥NaN和任何值都不相等，包括自身，要判断一个值是否为NaN可使用isNaN()函数；函数isFinite()，在参数不是NaN、Infinity或-Infinity的时候返回true；
	 * @note ⑦由于舍入误差，0.3和0.2之间的近似差值实际上不等于0.2和0.1之间的近似差值★ （page38）
	 */
	void knowledge_point02;

    /**
	 * @brief 3.2文本
	 *
	 * @note ①js通过字符串类型表示文本，字符串长度是其所含16位值的个数，js中没有表示单个字符的“字符型”；
	 * @note ②在ECMAScript3中，字符串直接量必须写在一行中，而在ECMAScript5中，字符串直接量可以拆分为数行，每行必须以反斜线(\\)结束，反斜线和行结束符都不算是字符串直接量的内容；
	 * @code 
       //转义字符 如果“\”字符位于没有在以下列出字符前，则会被忽略
	   \o       NUL字符（\u0000）
       \b       退格符（\u0008）
	   \t       水平制表符（\u0009）
	   \n       换行符（\u000A）
	   \v       垂直制表符（\u000B）
	   \f       换页符（\u000C）
	   \r       回车符（\u000D）
	   \"       双引号（\u0022）
	   \'       撇号或单引号（\u0027）
	   \\       反斜线（\u005C）
	   \xXX     由两位十六进制数XX指定的Latin-1字符
	   \uXXXX   由四位十六进制数XXXX指定的Unicode字符  
	 * @endcode
	 * @code
       //字符串处理常见函数
	   var s = "hello, world";   // 定义一个字符串
	   s.charAt(0)               // =>"h":第一个字符
	   s.charAt(s.length-1)      // =>"d":最后一个字符
	   s.substring(1,4)          // =>"ell":第2~4个字符
	   s.slice(1,4)              // =>"ell":同上
	   s.slice(-3)               // =>"rld":最后三个字符
	   s.indexOf("l")            // =>2:字符l首次出现的位置
       s.lastIndexOf("l")        // =>10:字符l最后一次出现的位置
	   s.indexOf("l",3)          // =>3:在位置3及之后首次出现字符l的位置 
	   s.split(", ")             // =>["hello", "world"]:分割成子串
	   s.replace("h", "H")       // =>"Hello, world":全文字符替换 
	   s.toUpperCase()           // =>"HELLO, WORLD":转成大写
	 * @endcode
	 * @note ③在js中字符串是固定不变的，类似replace()和toUpperCase()的方法都返回新字符串，原字符串本身并没有发生改变。
	 * @note ④在两条正斜线之间的文本构成了一个正则表达式直接量。第二条斜线之后也可以跟随一个或多个字母，用来修饰匹配模式的含义。
	 * @code
       //字符匹配常见函数（RegExp对象常见方法，字符串接收RegExp参数方法）
	   var text = “testing: 1, 2, 3”;  //文本示例
	   var pattern = /\d+/g            //匹配所有包含一个或多个数字的实例
	   pattern.test(text)              // =>true:匹配成功
	   text.search(pattern)            // =>9:首次匹配成功的位置
	   text.match(pattern)             // =>["1", "2" ,"3"]:所有匹配组成的数组
	   text.replace(pattern, "#")      // =>"testing: #, #, #"
	   text.split(/\D+/)               // =>["","1","2","3"]:用非数字字符截取字符串 
	 * @endcode
	 */
	void knowledge_point03;

	/**
	 * @brief 3.3布尔值
	 *
	 * @note ①除了以下值会被转成false外（undefined、unll、0、-0、NaN、""），其余的均为true;
	 * @note ②布尔值包含toString()方法，可使用该方法将字符串转换成"true"或者"false";
	 * @note ⑦尽管null和undefined是不同的，但他们都表示“值的空缺”，两者往往可以互换，“==”认为两种相等，“===”认为两者不等；
	 */
	void knowledge_point04;

	/**
	 * @brief 3.4null和undefined
	 *
	 * @note ①尽管null和undefined是不同的，但他们都表示“值的空缺”，两者往往可以互换，“==”认为两种相等，“===”认为两者不等；
	 * @note ②undefined表示系统级的，出乎意料的或类似错误的值的空缺；null是表示程序级的、正常的或者意料之中的值的空缺；
	 */
	void knowledge_point05;

	/**
	 * @brief 3.5全局对象
	 *
	 * @note ①全局对象在js中有着重要用途：全局对象的属性是全局定义的符号，js程序可以直接使用。当js解释器启动时（或者web浏览器加载新页面的时候），它将创建一个新的全局对象，并给他一组定义的初始属性；
	 * @code
       //全局属性，比如undefined、Infinity和NaN
	   //全局函数，比如isNaN()、parseInt()、eval()
	   //构造函数，比如Date()、RegExp()、String()、Object()和Array()
	   //全局对象，比如Math和JSON
	 * @endcode
	 * @note ②在客户端js中，在其表示的浏览器窗口中的所有Js代码中，Window对象充当了全局对象。这个全局对象有一个属性window引用其自身；
	 */
	void knowledge_point06;

    /**
	 * @brief 3.6包装对象★
	 *
	 * @note
	 * @code
	   //★此处需要了解一个重要机制
	   //我们看到字符串也同样具有属性和方法
	   var s = "hello world!";                                 //一个字符串
	   var word = s.substring(s.indexOf(" ")+1,s.length);      //使用字符串的属性

       //字符串既然不是对象，为什么它会有属性？？
       //重要机制：只要引用了字符串s的属性，js就会将字符串值通过调用new String(s)的方式转换成对象，这个对象继承了字符串的方法，并被用来处理属性的引用，一旦属性引用结束，这个新创建的对象就会销毁（其实在实现上并不一定创建或销毁这个临时对象，然而整个过程看起来是这样）。	   
	 * @endcode
	 * @note ①数字和布尔值也有各自的方法：通过Number()和Boolean()构造函数创建一个临时对象，这些方法的调用均是来自于这个临时对象。null和undefined没有包装对象：访问他们的属性会造成一个类型错误。
	 * @code
	   //思考一份代码★
       var s = "test";       //创建一个字符串
	   s.len = 4;            //给他设置一个属性（新建一个属性，并赋值4）
	   var t = s.len;        //=>undefined :查询这个值，由于修改只发生在第二行的临时对象上，而第三行会重新创建一个临时对象，之前对象的属性值不会保留；
	 * @endcode
	 */
	void knowledge_point07;

    /**
	 * @brief 3.7不可变的原始值和可变的对象引用
	 *	  
	 * @note ①js中的原始值与对象有着根本区别。原始值是不可更改的：任何方法都无法更改一个原始值。字符串中所有的方法看上去返回了一个修改后的字符串，实际上返回的是一个新的字符串值。
	 * @note ②原始值的比较是值比较；
	 * @note ③对象的比较并非值的比较，而是引用的比较：即使两个对象包含同样的属性及相同的值，他们也不是相等的。各个索引元素完全相等的两个数组也不相等；当且仅当它们引用同一个基对象时，他们才相等；
	 */
	void knowledge_point08;

	/**
	 * @brief 3.8类型转换
	 *	  
	 * @note ①“==”等于运算符在判断两个值是否相等时做了一些类型转换，而“===”恒等运算符在判断相等时并未做任何类型转换；
	 * @note ②做显式类型转换最简单的方法就是使用Boolean()、Number()、String()或者Object()函数；
	 * @note ③js中某些运算符会做隐式的类型转换，代码中常见的这种类型转换惯用法如下：
	 * @code
           x + "" //等价于String(x)
		   +x     //等价于Number(x),也可以写成x-0
		   !!x    //等价于Boolean(x),注意是两个叹号
	 * @endcode
	 * @code
           //更加精准的字符串与数字转换函数
		   //toString()方法：Number类定义的toString()方法可以接收表示转换基数的可选参数，如果不指定此参数，转换规则将是基于10进制；  
		   var n = 17;
           binary_string = n.toString(2);    //转换为“10001”
		   octal_string = n.toString(8);     //转换为“021”
		   hex_string = n.toString(16);      //转换为“ox11”

		   //toFixed()方法：根据小数点后的指定位数将数字转换为字符串，它从不使用指数计数法；（会适当的四舍五入或填充0）
		   var n = 123456.789;
           n.toFixed(0); //=> "123456"
		   n.toFixed(2); //=> "123456.78"
		   n.toFixed(5); //=> "123456.78900"

		   //toExponential()方法：使用指数计数法将数字转换为指数形式的字符串，其中小数点前只有一位，小数点后的位数由参数指定；（会适当的四舍五入或填充0）
           n.toExponential(1); //=> "1.2e+5"
		   n.toExponential(3); //=> "1.235e+5"
		 
		   //toPrecision()方法：根据指定的有效数字位数将数字转换成字符串。如果有效数字的位数少于整数部分的位数，则转换成指数形式；（会适当的四舍五入或填充0）
		   n.toPrecision(4); //=> "1.235e+5"
		   n.toPrecision(7); //=> "123456.8"
		   n.toPrecision(10); //=> "123456.7890"

		   //通过Number()转换函数传入一个字符串，它会试图将其转换为一个整数或者浮点数直接量，该方法只能基于10进制转换，并且不能出现非法的尾随字符。

		   //parseInt()函数和parseFloat()函数（他们是全局函数，不属于任何类的方法）更加灵活，详情参考page51
	 * @endcode
	 * @note ④对象转换成原始值
	 * @note  A对象到布尔值：所有的对象都转换成true；
	 * @note  B对象到字符串：对象的toString()方法；  若有toString()先调用，否则调用valueOf(),否则返回类型错误异常；
	 * @note  C对象到数字：对象的valueOf()方法；    若有valueOf()先调用，否则调用toString(),否则返回类型错误异常；
	 */
	void knowledge_point09;

	/**
	 * @brief 3.9变量申明
	 *	  
	 * @note ①js中使用关键字var申明变量；
	 */
	void knowledge_point10;

	/**
	 * @brief 3.10变量作用域
	 *	  
	 * @note ①全局变量拥有全局作用域，在js代码的任何地方都有定义；函数内申明的变量只在函数体内有定义；
	 * @note ②在函数体内，局部变量的优先级高于同名的全局变量；
	 * @note ③尽管在全局作用域编写代码时可以不写var语句，但申明局部变量时则必须使用var语句。否则有可能误修改全局变量★
	 * @note ④js中没有块级作用域，取而代之的是函数作用域：变量在申明它们的函数体以及这个函数体嵌套的任意函数体内都是有定义的★
	 * @note ⑤js的函数作用域是指在函数内申明的所有变量在函数体内始终是可见的，这意味着在申明之前甚至已经可用。js的这个特性被非正式的称为“申明提前”，即js函数里申明的所有变量都被“提前”至函数体的顶部；★
	 * @code
       var scope = "global";
	   function f() {
           console.log(scope);   //=>"undefined",而不是"global"
		   var scope = "local";  //变量在这里赋初始值，但变量本身在函数体内任何地方均是有定义的
		   console.log(scope);   //输出"local"
	   }
	 * @endcode
	 * @note ⑤当申明一个全局变量的时，实际是定义了全局对象的一个属性；
	 */
	void knowledge_point11;
};