/**
 * @brief 第二章 词法结构
 */
class Chapter2
{
public:
    /**
	 * @brief 2.1字符集
	 *
	 * @note ①JavaScript程序是用Unicode字符集编写的。Unicode是ASCII和Latin-1的超集，几乎支持所有语言；
	 * @note ②JavaScript区分大小写，HTML不区分大小写；
	 * @note ③JavaScript会忽略程序中的空格，多数情况下忽略换行符；
	 * @note ④Unicode转义序列均以\\u为前缀，其后跟随4个十六进制数（例如\\u00e9)
	 */
	void knowledge_point1;

    /**
	 * @brief 2.2注释
	 *
	 * @note ①单行、多行注释风格与c++一致
	 */
	void knowledge_point2;

    /**
	 * @brief 2.4标识符和保留字
	 *
	 * @note ①javascript标识符必须以字母、下划线(_)或美元符($)开始。后续的字符可以是字母、数字、下划线或美元符。
	 * @note ②关键字和预定义全局变量
	 * @code 
       //关键字
	   break    delete  function   return typeof
	   case     do      if         switch var
	   catch    else    in         this   void
	   continue false   instanceof throw  while
	   debugger finally new        true   with
	   default  for     null       try

	   //ECMAScript 5保留关键字
	   class const enum export extends import super

	   //严格模式下的保留字
	   implements let private public protected yield interface package static

	   //不完全保留字，但不能作为变量名、函数名、参数名
	   arguments eval

	   //ECMAScript 3将java所有关键字都列为自己的保留字，尽管5中放宽限制，此处不再列举

	   //javascript预定义的全局变量和函数，应当避免使用它们的名字作为变量名和函数名
	   arguments     encodeURI            Infinity    Number          RegExp
	   Array         encodeURIComponent   isFinite    Object          String
	   Boolean       Error                isNaN       parseFloat      SyntaxError
	   Date          eval                 JSON        parseInt        TypeError
	   decodeURI     EvalError            Math        RangeError      undefined
	   Function      decodeURIComponent   NaN         ReferenceError  URIError
	 * @endcode
	 * @note ③javascript的具体实现可能定义独有的全局变量和函数，每一种特定的javascript运行环境（客户端、服务端等）都有自己的一个全局属性列表；
	 */
	void knowledge_point3;

	/**
	 * @brief 2.5可选的分号
	 *
	 * @note ①分号可选仅作了解，实际编码过程中尽可能使用分号来明确标记语句的结束。
	 * @note ②常用规则：如果当前语句和下一行语句无法合并解析，javascript则在第一行后填补分号；
	 * @note ③两个特例：return、break、continue关键字后紧跟换行，js则会在换行处填补分号；
	 * @note           “++”、“--”运算符，如果将其用做后缀表达式，他和表达式应处于同一行，否则其将会作为下一行的前缀操作符；
	 */
	void knowledge_point4;
};