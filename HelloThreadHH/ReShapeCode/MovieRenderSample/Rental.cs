using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloThreadHH.ReShapeCode.MovieRenderSample
{
    // means that customer render a movie
    public class Rental
    {
        private Movie movie;
        private int daysRented;

        public Rental(Movie movie,int dayRented)
        {
            this.movie = movie;
            this.daysRented = daysRented;
        }

        public int GetDaysRented()
        {
            return daysRented;
        }

        public Movie getMovie()
        {
            return movie;
        }
    }
}
