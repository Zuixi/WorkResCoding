using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloThreadHH.DelegateObserver
{
   public class Thermostat
    {
        // 定义数据委托类型
        public delegate void TempratureChangeHandler(float newTemprature);

        // 定义事件发布者
        public TempratureChangeHandler onTempratureChange
        {
            get
            {
                return _OnTempratureChange;
            }
            set
            {
                _OnTempratureChange = value;
            }
        }

        private TempratureChangeHandler _OnTempratureChange;

        public float CurrentTemprature
        {
            get
            {
                return _CurrentTemprature;
            }
            set
            {
                if (value != CurrentTemprature)
                {
                    // 调用一个委托之前，必须判断其之前是否为控制，不然有可能会引发异常

                    /****************
                    _CurrentTemprature = value;
                    // 告诉订阅者温度发生变化
                    onTempratureChange(_CurrentTemprature);
                    ********************************/

                    _CurrentTemprature = value;

                    if (onTempratureChange != null)
                    {
                        // 为了避免订阅者发生异常而中断，导致后面的订阅者不能继续操作，必须手动遍历订阅者列表，并且单独调用他们
                        foreach(TempratureChangeHandler handler in onTempratureChange.GetInvocationList())
                        {
                            try
                            {
                                handler(value);
                            }
                            catch (Exception exception)
                            {
                                Console.WriteLine(exception.Message);
                            }
                        }
                    }
                }
            }
        }

        private float _CurrentTemprature;
    }
}
