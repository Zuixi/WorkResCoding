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
                    _CurrentTemprature = value;

                    // 告诉订阅者温度发生变化
                    onTempratureChange(_CurrentTemprature);
                }
            }
        }

        private float _CurrentTemprature;
    }
}
