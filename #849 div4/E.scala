import scala.io.StdIn._
import java.io._
import java.nio.file.Files
import java.nio.file.Path
import java.util.StringTokenizer
import scala.io.Codec

object Main {

    class Scanner(reader: LineNumberReader) extends Iterator[String] with AutoCloseable {
        def this(reader: BufferedReader) = this(new LineNumberReader(reader))
        def this(reader: Reader) = this(new BufferedReader(reader))
        def this(inputStream: InputStream)(implicit codec: Codec) = this(new InputStreamReader(inputStream, codec.charSet))
        def this(path: Path)(implicit codec: Codec) = this(Files.newBufferedReader(path, codec.charSet))
        def this(file: File)(implicit codec: Codec) = this(file.toPath)(codec)
        def this(str: String) = this(new StringReader(str))

        private[this] val tokenizers = Iterator.continually(reader.readLine()).takeWhile(_ != null).map(new StringTokenizer(_)).filter(_.hasMoreTokens)
        private[this] var current: Option[StringTokenizer] = None

        @inline private[this] def tokenizer(): Option[StringTokenizer] = current.find(_.hasMoreTokens) orElse {
            current = if (tokenizers.hasNext) Some(tokenizers.next()) else None
            current
        }

        def nextLine(): String = {
            current = None   // reset
            reader.readLine()
        }
        def lineNumber: Int = reader.getLineNumber
        def line(): String = tokenizer().get.nextToken("\n\r")
        def nextString(): String = next()
        def nextChar(): Char = next().ensuring(_.length == 1).head
        def nextBoolean(): Boolean = next().toBoolean
        def nextByte(radix: Int = 10): Byte = java.lang.Byte.parseByte(next(), radix)
        def nextShort(radix: Int = 10): Short = java.lang.Short.parseShort(next(), radix)
        def nextInt(radix: Int = 10): Int = java.lang.Integer.parseInt(next(), radix)
        def nextLong(radix: Int = 10): Long = java.lang.Long.parseLong(next(), radix)
        def nextBigInt(radix: Int = 10): BigInt = BigInt(next(), radix)
        def nextFloat(): Float = next().toFloat
        def nextDouble(): Double = next().toDouble
        def nextBigDecimal(): BigDecimal = BigDecimal(next())
        override def next() = tokenizer().get.nextToken()
        override def hasNext = tokenizer().nonEmpty
        override def close() = reader.close()
    }

  val sc = new Scanner(System.in)
  
    def main(args: Array[String]): Unit = {
        // input a number T
        var T = sc.nextInt()
        while (T > 0) {
            T = T-1
            var N = sc.nextInt()
            // read N numbers in a line to a array
            var a = new Array[Long](N)
            for (i <- 0 until N) {
                a(i) = sc.nextLong()
            }
            // 2-d array of N rows and 2 columns long long
            var dp = Array.ofDim[Long](N, 4)
            dp(0)(0) = a(0)
            dp(0)(1) = a(0)
            dp(0)(2) = -1000000000000000000L
            dp(0)(3) = -1000000000000000000L
            for (i <- 1 until N) {
                dp(i)(0) = Math.max(dp(i-1)(0), dp(i-1)(1)) + a(i)
                dp(i)(1) = Math.max(dp(i-1)(2), dp(i-1)(3)) + a(i)
                dp(i)(2) = Math.max(dp(i-1)(0), dp(i-1)(1)) - 2 * a(i-1) - a(i)
                dp(i)(3) = Math.max(dp(i-1)(2), dp(i-1)(3)) + 2 * a(i-1) - a(i)
            }
            println(Math.max(dp(N-1)(0), Math.max(dp(N-1)(1), Math.max(dp(N-1)(2), dp(N-1)(3)))))
        }
    }
}
