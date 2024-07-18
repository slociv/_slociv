using MinHook;
using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;
namespace csLucifer
{
    public partial class dlgLucifer : Form
    {
        //从dll导入send和recv函数
        // Import the send and recv functions from ws2_32.dll
        [DllImport("ws2_32.dll", SetLastError = true)]
        public static extern int send(IntPtr s, IntPtr buf, int len, int flags);

        [DllImport("ws2_32.dll", SetLastError = true)]
        public static extern int recv(IntPtr s, IntPtr buf, int len, int flags);

        //定义与原send和recv匹配的委托函数
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        delegate int SendDelegate(IntPtr s, IntPtr buf, int len, int flags);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        delegate int RecvDelegate(IntPtr s, IntPtr buf, int len, int flags);

        //定义变量存储这个元函数
        static SendDelegate originalSend;
        static RecvDelegate originalRecv;

        //send 的改道把手函数
        static int DetourSend(IntPtr s, IntPtr buf, int len, int flags)
        {
            byte[] buffer = new byte[len];
            Marshal.Copy(buf, buffer, 0, len);
            Console.WriteLine("Send Hooked: " + BitConverter.ToString(buffer));
            return originalSend(s, buf, len, flags);
        }
        //recv 的改道把手函数
        static int DetourRecv(IntPtr s, IntPtr buf, int len, int flags)
        {
            int result = originalRecv(s, buf, len, flags);
            if (result > 0)
            {
                byte[] buffer = new byte[result];
                Marshal.Copy(buf, buffer, 0, result);
                Console.WriteLine("Recv Hooked: " + BitConverter.ToString(buffer));
            }
            return result;
        }
        private HookEngine engine;
        public dlgLucifer()
        {
            InitializeComponent();
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void dlgLucifer_Load(object sender, EventArgs e)
        {
            //初始化minhook
            engine = new HookEngine();
            originalSend = engine.CreateHook("ws2_32.dll", "send", new SendDelegate(DetourSend));
            originalRecv = engine.CreateHook("ws2_32.dll", "recv", new RecvDelegate(DetourRecv));
            engine.EnableHooks();
        }

        private void dlgLucifer_FormClosed(object sender, FormClosedEventArgs e)
        {
            engine.DisableHooks();
            engine.Dispose();
        }
    }
}
