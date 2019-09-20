using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloThreadHH.DelegateObserver
{
    public class Cooler
    {
        public Cooler(float temprature)
        {
            Temprature = temprature;
        }

        public float Temprature
        {
            get
            {
                return _Temprature;
            }
            set
            {
                _Temprature = value;
            }
        }

        private float _Temprature;

        public void OnTempratureChanged(float newTemptature)
        {
            if(newTemptature > Temprature)
            {
                Console.WriteLine("Cooler: On");
            }
            else
            {
                Console.WriteLine("Cooler: off");
            }
        }
    }

    public class Heater
    {
        public Heater(float temprature)
        {
            Temprature = temprature;
        }
        public float Temprature
        {
            get
            {
                return _Temprature;
            }
            set
            {
                _Temprature = value;
            }
        }

        private float _Temprature;
        public void OnTempratureChanged(float newTemptature)
        {
            if (newTemptature < Temprature)
            {
                Console.WriteLine("Heater: On");
            }
            else
            {
                Console.WriteLine("Heater: off");
            }
        }


    }
}
