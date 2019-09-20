using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloThreadHH.DelegateObserver
{
    // 使用事件来解决委托存在的问题
    public class TherSuper
    {
        public class TempratureArgs : EventArgs
        {
            public TempratureArgs(float temprature)
            {
                NewTemprature = temprature;
            }

            public float NewTemprature
            {
                get { return _newTemprature; }
                set
                {
                    _newTemprature = value;
                }
            }

            private float _newTemprature;

        }

        public delegate void TemperatureChangeHandler(object sender, TempratureArgs newTemprature);

        //定义事件发布者

        public event TemperatureChangeHandler OnTempratureChange = delegate { };


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

                    if (OnTempratureChange != null)
                    {
                        // 告诉订阅者
                        OnTempratureChange(this, new TempratureArgs(value));
                    }
                }
            }
        }

        private float _CurrentTemprature;
    }


}
