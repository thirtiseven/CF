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
            // input a number N and a string S
            var N = sc.nextInt()
            var s = sc.next()
            //Given a string s, split it into two non-empty strings a and b
            //to make sum of different char in a and b maximum
            // use a map to store the number of each char in a
            var mapa = scala.collection.mutable.Map[Char, Int]()
            var mapb = scala.collection.mutable.Map[Char, Int]()
            for (i <- 0 until N) {
                if (mapa.contains(s(i))) {
                    mapa(s(i)) = mapa(s(i)) + 1
                } else {
                    mapa(s(i)) = 1
                }
            }
            var ans = mapa.size
            // from the end of the string, move the char to b
            for (i <- N until 0 by -1) {
                // println("i: " + i)
                if (mapb.contains(s(i-1))) {
                    mapb(s(i-1)) = mapb(s(i-1)) + 1
                } else {
                    mapb(s(i-1)) = 1
                }
                mapa(s(i-1)) = mapa(s(i-1)) - 1
                if (mapa(s(i-1)) == 0) {
                    mapa.remove(s(i-1))
                }
                // print("mapa: " + mapa.size + " mapb: " + mapb.size + "\n")
                ans = Math.max(ans, mapa.size + mapb.size)
            }
            println(ans)
            // println("======")
        }
    }
}
