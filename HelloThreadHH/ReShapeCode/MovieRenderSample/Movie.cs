using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloThreadHH.ReShapeCode.MovieRenderSample
{
    public class Movie
    {
        public const int CHILDRENS = 2;
        public const int REGULAR = 0;
        public const int NEW_RALEASE = 1;

        private string title;
        private int priceCode;

        public Movie(string title,int priceCode)
        {
            this.title = title;
            this.priceCode = priceCode;
        }

        public int GetPriceCode()
        {
            return priceCode;
        }

        public bool SetPriceCode(int priceCode)
        {
            this.priceCode = priceCode;
            return true;
        }

        public string GetTitleOfMovie()
        {
            return title;
        }
    }
}
