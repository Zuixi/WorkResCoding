using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using HelloThreadHH.DelegateObserver;
namespace HelloThreadHH
{
    class Program
    {
        static int TakesAWhile(int data,int ms)
        {
            Console.WriteLine("TakesAWhile started!");
            Thread.Sleep(ms);
            Console.WriteLine("TakeAWhile completed!");
            return ++data;
        }

        // 使用任务
        static void TaskMethod()
        {
            Console.WriteLine("Running in a task!");
            Console.WriteLine("Task is = {0}", Task.CurrentId);
        }
        //使用委托调用
        public delegate int TakesAWhileDelegate(int data, int ms);
        static void Main(string[] args)
        {
            Console.WriteLine("Hello,World");
            /*
            // asynchronous by using a delegatel
            TakesAWhileDelegate dl = TakesAWhile;
            IAsyncResult ar = dl.BeginInvoke(1, 3000, null, null);
            while(!ar.IsCompleted)
            {
                Console.Write(". ");
                Thread.Sleep(50);
            }
            */
    

            Thermostat thermostat = new Thermostat();
            Heater heater = new Heater(40);
            Cooler cooler = new Cooler(70);
            string temprature;

            // 测试委托符号的使用
            Thermostat.TempratureChangeHandler delegate1;
            Thermostat.TempratureChangeHandler delegate2;
            Thermostat.TempratureChangeHandler delegate3;

            // use Constructor for cs
            delegate1 = heater.OnTempratureChanged;
            delegate2 = cooler.OnTempratureChanged;

            Console.WriteLine("Invoke both delegates: ");
            delegate3 = delegate1;
            delegate3 += delegate2;
            delegate3(90);

            Console.WriteLine("only Invoke delegate2: ");
            delegate3 -= delegate1;
            delegate3(20);

            Console.WriteLine(" delegate end!");

            // 多播委托
            thermostat.onTempratureChange += heater.OnTempratureChanged;
            thermostat.onTempratureChange += cooler.OnTempratureChanged;

            Console.Write("Enter temprature: ");
            temprature = Console.ReadLine();
            thermostat.CurrentTemprature = float.Parse(temprature);

            Console.WriteLine();

            // 爸爸儿子任务
            var parent = new Task(ParentTask);
            parent.Start();
            Thread.Sleep(2000);
            Console.WriteLine(parent.Status);
            Thread.Sleep(4000);
            Console.WriteLine(parent.Status);
            //使用Thread类实现方法
            var t1 = new Thread(ThreadMain);
            t1.Start();
            Console.WriteLine("This is a main thread");

            // using task factory
            TaskFactory tf = new TaskFactory();
            Task task1 = tf.StartNew(TaskMethod);

            // using the task factory via a task
            Task task2 = Task.Factory.StartNew(TaskMethod);

            // using Task constuctor
            Task task3 = new Task(TaskMethod);
            task3.Start();
            Console.WriteLine();

            // 连续任务的执行
            Task a1 = new Task(DoOnFirst);
            Task a2 = a1.ContinueWith(DoOnSecond);
            Task a3 = a1.ContinueWith(DoOnSecond);
            Task a4 = a2.ContinueWith(DoOnSecond);

            // 只在任务失败是得到执行
            Task a5 = a1.ContinueWith(DoOnSecond, TaskContinuationOptions.OnlyOnFaulted);

            Console.ReadLine();
        }

        static void ThreadMain()
        {
            Console.WriteLine("Running in a thread!");
        }

        // 第一个需要做的任务
        static void DoOnFirst()
        {
            Console.WriteLine("doing some task{0}", Task.CurrentId);
            Thread.Sleep(3000);
        }

        //第一个任务完成后做第二个任务
        static void DoOnSecond(Task t)
        {
            Console.WriteLine("task {0} finished!", t.Id);
            Console.WriteLine("this is task id {0}", Task.CurrentId);
            Console.WriteLine("do some cleanup");
            Thread.Sleep(3000);
        }

        // 父鸡任务
        static void ParentTask()
        {
            Console.WriteLine("task id {0}", Task.CurrentId);
            // 创建儿子任务
            var childTask = new Task(ChildTask);
            childTask.Start();
            Thread.Sleep(1000);
            Console.WriteLine("Parent started a child");
        }

        static void ChildTask()
        {
            Console.WriteLine("child is me");
            Thread.Sleep(1000);
            Console.WriteLine("ParentTask started child");
        }
    }
}
