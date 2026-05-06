#pragma once

class Bill {
private:
    int billId;
    int reservationId;
    double totalBillAmount;
    bool billPaid;

public:
    Bill(int billId, int reservationId, double totalBillAmount)
        : billId(billId), reservationId(reservationId),
          totalBillAmount(totalBillAmount), billPaid(false) {}

    // Getters / Setters
    int getBillId() { return billId; }
    int getReservationId() { return reservationId; }
    double getTotalBillAmount() { return totalBillAmount; }
    bool isBillPaid() { return billPaid; }
    void setBillPaid(bool paid) { billPaid = paid; }
};
