using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloThreadHH.LockThread
{
   public class SharedState
    {
        public int state = 0;
        public int State
        {
            get
            {
                lock (syncRoot)
                {return state;} 
            }
            set
            {
                lock(syncRoot)
                { state = value; }
            }
        }

        // 使用SyncRoot模式
        private object syncRoot = new object();

        // 使用类的原子功能
        public int IncrementState()
        {
            lock(syncRoot)
            { return ++state; }
        }
    }


    public class Job
    {
        SharedState sharedState;
        
        public Job(SharedState sharedState)
        {
            this.sharedState = sharedState;
        }

        public void DoTheJob()
        {
            // 让state 递增50000次
            for (int i = 0; i < 50000; i++)
            {
                lock(sharedState)
                { sharedState.State += 1; }               
            }
        }
    }
}
