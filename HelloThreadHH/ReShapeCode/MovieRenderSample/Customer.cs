using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloThreadHH.ReShapeCode.MovieRenderSample
{
    public class Customer
    {
        private string name;
        private int age;
        private string email;
        private List<Rental> rentals = new List<Rental>();

        public Customer(string name)
        {
            this.name = name;
        }

        public void AddRental(Rental tag)
        {
            rentals.Add(tag);
        }

        public string GetName()
        {
            return this.name;
        }

        public String stateMent()
        {
            double totalAmount = 0;
            int frequentRenterPoints = 0;
            Enumerable mesOfRentals = rentals.ElementAt(1);
            string result = "Rental Record for " + GetName() + "\n";

            while(true)
            {

                // add frequent renter points
                frequentRenterPoints++;

                // add bonus for a two day release rental

            }
        }

            
    }
}
