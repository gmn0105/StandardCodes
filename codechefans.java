import java.io.* ;
import java.lang.reflect.Array;
import java.util.* ;
public class Main
{
    static BufferedReader reader;
    static StringTokenizer tokenizer;
 
    static void init(InputStream input)
    {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }
 
    static String next() throws IOException
    {
        while (!tokenizer.hasMoreTokens())
        {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
 
    static long nextInt() throws IOException
    {
        return Long.parseLong(next());
    }
 
    public static int ri() throws IOException
    {
        return (int) nextInt();
    }
 
    public static long rl() throws IOException
    {
        return nextInt();
    }
 
    public static double rd() throws NumberFormatException, IOException
    {
        return Double.parseDouble(next());
    }
 
    static void print_a(int[] arr)
    {
        for (int i = 0; i < arr.length; i++)
        {
            print(arr[i] + " ");
        }
        println();
    }
 
    public static int[] ria(int n) throws IOException
    {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = ri();
        }
        return a;
    }
 
    public static long[] rla(int n) throws IOException
    {
        long[] a = new long[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = rl();
        }
        return a;
    }
 
    public static int p(int i)
    {
        return (int) Math.pow(2, i);
    }
 
    static PrintWriter writer;
 
    static void outit(OutputStream outputStream)
    {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }
 
    static void print(Object... objects)
    {
        for (int i = 0; i < objects.length; i++)
        {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }
 
    static void println(Object... objects)
    {
        print(objects);
        writer.println();
    }
 
    static void close()
    {
        writer.close();
    }
 
    static void flush()
    {
        writer.flush();
    }
 
    public static void main(String[] args) throws IOException
    {
        init(System.in);
        outit(System.out);
        int t = (int) nextInt();
        for (int i = 0; i < t; i++)
            output();
        flush();
        close();
    }
    static int L;
    static int R;
    static int[] a;
    static int n;
    static int q;
    static int[] counter;
    static int[] left_str;
    static int[] right_str;
    public static void output() throws IOException
    {
        int n  = ri() ;
        int k = ri() ;
        long x = rl() ;
        int m = ri() ;
        int s = ri()-1 ;
        ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>() ;
        ArrayList<ArrayList<Long>> e = new ArrayList<ArrayList<Long>>() ;
        for (int i = 0; i <n ; i++)
        {
            g.add(new ArrayList<Integer>()) ;
            e.add(new ArrayList<Long>()) ;
        }
        for (int i = 0; i <m ; i++)
        {
            int u = ri()-1 ;
            int v= ri()-1 ;
            long weight = rl() ;
            g.get(u).add(v) ;
            g.get(v).add(u) ;
            e.get(u).add(weight);
            e.get(v).add(weight);
        }
        final long[] d = new long[n];
        long INFINITY = (long)1e18 ;
        for (int i = 0; i < n; i++)
        {
            if(i!=s)
            {
                d[i] = INFINITY;
            }
        }
        TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                if (d[a] < d[b]) return -1;
                if (d[a] > d[b]) return 1;
                return a - b;
            }
        });
        q.add(s);
        while (!q.isEmpty())
        {
            int u = q.pollFirst();
            for (int i = 0; i < g.get(u).size(); i++) {
                int v = g.get(u).get(i);
                long duv = e.get(u).get(i);
                if (d[v] > d[u] + duv) {
                    q.remove(v);
                    d[v] = d[u] + duv;
                    q.add(v);
                }
            }
        }
        // end dijkstra
        long min_d = Long.MAX_VALUE ;
        int min_v = 0 ;
        for (int i = 0; i <k ; i++)
        {
            if(d[i]<min_d)
            {
                min_v = i ;
                min_d = d[i] ;
            }
        }
        for (int i = 0; i <k ; i++)
        {
            if(i!=min_v)
            {
                g.get(i).add(min_v);
                g.get(min_v).add(i) ;
                e.get(i).add(x);
                e.get(min_v).add(x);
            }
        }
        INFINITY = (long)1e18 ;
        for (int i = 0; i < n; i++)
        {
            if(i!=s)
            {
                d[i] = INFINITY;
            }
        }
        q = new TreeSet<Integer>(new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                if (d[a] < d[b]) return -1;
                if (d[a] > d[b]) return 1;
                return a - b;
            }
        });
        q.add(s);
        while (!q.isEmpty())
        {
            int u = q.pollFirst();
            for (int i = 0; i < g.get(u).size(); i++) {
                int v = g.get(u).get(i);
                long duv = e.get(u).get(i);
                if (d[v] > d[u] + duv) {
                    q.remove(v);
                    d[v] = d[u] + duv;
                    q.add(v);
                }
            }
        }
//        println(min_v);
        for (int i = 0; i <n ; i++)
        {
            print(d[i]+" ") ;
        }
        println() ;
    }
}