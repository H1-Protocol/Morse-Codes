#include <iostream>
#include <iomanip>

using namespace std;
class SalesQuarter {
public:
    double salesQuarter;
    SalesQuarter(double s = 0.0) : salesQuarter(s) {}
};

class SalesPerson {
public:
    int id;
    SalesQuarter salesQuarters[4];
    static int totalSalesPersons; 

    SalesPerson(int i = 0, double q1 = 0, double q2 = 0, double q3 = 0, double q4 = 0) : id(i) {
        salesQuarters[0] = SalesQuarter(q1);
        salesQuarters[1] = SalesQuarter(q2);
        salesQuarters[2] = SalesQuarter(q3);
        salesQuarters[3] = SalesQuarter(q4);
        totalSalesPersons++; 
    }

    double getTotal() const {
        double sum = 0;
        for (int i = 0; i < 4; i++) sum += salesQuarters[i].salesQuarter;
        return sum;
    }
};

int SalesPerson::totalSalesPersons = 0;

class SalesReport {
    SalesPerson* salespersons[6]; 

public:
    void addSalesPerson(SalesPerson& sp, int index) {
        if (index >= 0 && index < 6) {
            salespersons[index] = &sp;
        }
    }

    void generateReport() {
        cout << "========= Annual Sales Report =========" << endl;
        cout << "ID\tQT1\tQT2\tQT3\tQT4\tTotal" << endl;

        double qtTotals[4] = {0, 0, 0, 0};
        double maxSales = -1;
        int maxId = -1;
        double maxQtAmount = -1;
        int maxQtNum = -1;

        for (int i = 0; i < 6; i++) {
            double total = salespersons[i]->getTotal();
            cout << salespersons[i]->id << "\t";
            
            for (int q = 0; q < 4; q++) {
                double val = salespersons[i]->salesQuarters[q].salesQuarter;
                cout << val << "\t";
                qtTotals[q] += val;
                
                if (val > maxQtAmount) { maxQtAmount = val; maxQtNum = q + 1; }
            }
            cout << total << endl;
            
            if (total > maxSales) { maxSales = total; maxId = salespersons[i]->id; }
        }

        cout << "Total\t" << qtTotals[0] << "\t" << qtTotals[1] << "\t" 
             << qtTotals[2] << "\t" << qtTotals[3] << endl;
        cout << "Max Sale by SalesPerson: ID = " << maxId << ", Amount = $" << maxSales << endl;
        cout << "Max Sale by Quarter: Quarter = " << maxQtNum << ", Amount = $" << maxQtAmount << endl;
        cout << "Total Salespersons Created: " << SalesPerson::totalSalesPersons << endl;
    }
};

int main() {
    SalesPerson sp1(2708, 1892.00, 0.00, 494.00, 322.00);
    SalesPerson sp2(10258, 343.00, 892.00, 9023.00, 0.00);
    SalesPerson sp3(3397, 1395.00, 1901.00, 0.00, 101.00);
    SalesPerson sp4(10619, 893.00, 892.00, 8834.00, 0.00);
    SalesPerson sp5(5326, 2882.00, 1221.00, 0.00, 1223.00);
    SalesPerson sp6(4705, 893.00, 0.00, 392.00, 3420.00);
    
    SalesReport report;
    report.addSalesPerson(sp1, 0);
    report.addSalesPerson(sp2, 1);
    report.addSalesPerson(sp3, 2);
    report.addSalesPerson(sp4, 3);
    report.addSalesPerson(sp5, 4);
    report.addSalesPerson(sp6, 5);
    
    report.generateReport();
    return 0;
}