import os

base_cpp = r"C:\Users\sasachdeva\OneDrive - Microsoft\Desktop\Learning\Cpp\lld-lowleveldesign"

files = {}

# ============================================================
# TEMPLATE METHOD PATTERN
# ============================================================

files[os.path.join(base_cpp, "behavioralpatterns", "templatemethod", "PaymentFlow.h")] = r'''#pragma once

#include <iostream>
#include <string>

using namespace std;

// Abstract class
class PaymentFlow {
public:
    virtual ~PaymentFlow() = default;

    // Abstract methods - these methods are implemented by the subclasses.
    virtual void validateRequest() = 0;

    virtual void debitAmount() = 0;

    virtual void calculateFees() = 0;

    virtual void creditAmount() = 0;

    // Template method: which defines the order of steps to execute the task.
    void sendMoney() {
        // step 1
        validateRequest();
        // step 2
        debitAmount();
        // step 3
        calculateFees();
        // step 4
        creditAmount();
    }

    // Hook method: which can be overridden by the subclasses.
    virtual bool requiresOTPAuthentication() {
        return false; // Default: authentication not required
    }

    // Common method: All subclasses share this common functionality.
    void logTransaction() {
        cout << "Transaction Completed!" << endl;
    }
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "templatemethod", "BankTransfer.h")] = r'''#pragma once

#include "PaymentFlow.h"

using namespace std;

// Concrete class
class BankTransfer : public PaymentFlow {
public:
    void validateRequest() override {
        cout << "[+] Specific Validation Logic for Bank Transfer" << endl;
    }

    void debitAmount() override {
        cout << "[+] Specific Debit Amount Logic for Bank Transfer" << endl;
    }

    void calculateFees() override {
        cout << "[+] Specific Fee Calculation Logic for Bank Transfer. 0% Fees is applied." << endl;
    }

    void creditAmount() override {
        cout << "[+] Specific Credit Amount Logic for Bank Transfer. Full amount is credited." << endl;
    }
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "templatemethod", "MerchantPayment.h")] = r'''#pragma once

#include "PaymentFlow.h"

using namespace std;

// Concrete class
class MerchantPayment : public PaymentFlow {
public:
    void validateRequest() override {
        cout << "[+] Specific Validation Logic for Merchant Payment" << endl;
    }

    void debitAmount() override {
        if (requiresOTPAuthentication()) {
            cout << "[+] Perform OTP Authentication." << endl;
        }
        cout << "[+] Specific Debit Amount Logic for Merchant Payment" << endl;
    }

    void calculateFees() override {
        cout << "[+] Specific Fee Calculation Logic for Merchant Payment. 2% Fees is applied." << endl;
    }

    void creditAmount() override {
        cout << "[+] Specific Credit Amount Logic for Merchant Payment. Remaining amount is credited." << endl;
    }

    // Hook method - overridden by subclass
    bool requiresOTPAuthentication() override {
        return true;
    }
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "templatemethod", "TemplateDemo.cpp")] = r'''#include <iostream>
#include "PaymentFlow.h"
#include "BankTransfer.h"
#include "MerchantPayment.h"

using namespace std;

// Client class
int main() {
    cout << "###### Template Method Design Pattern ######" << endl;

    // Bank Transfer
    cout << "===== Bank Transfer =====" << endl;
    PaymentFlow* bankTransfer = new BankTransfer();
    bankTransfer->sendMoney(); // Template method
    bankTransfer->logTransaction(); // Common method

    // Merchant Payment
    cout << "===== Merchant Payment =====" << endl;
    PaymentFlow* merchantPayment = new MerchantPayment();
    merchantPayment->sendMoney(); // Template method
    merchantPayment->logTransaction(); // Common method

    delete bankTransfer;
    delete merchantPayment;

    return 0;
}
'''

# ============================================================
# VISITOR PATTERN - PROBLEM
# ============================================================

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "problem", "SuiteHotelRoom.h")] = r'''#pragma once

#include <iostream>
#include <string>

using namespace std;

// Bloated Element class with multiple operations
class SuiteHotelRoom {
private:
    string roomNumber;
    string numberOfRooms;

public:
    SuiteHotelRoom(string roomNumber, string numberOfRooms)
        : roomNumber(roomNumber), numberOfRooms(numberOfRooms) {}

    void clean() {
        cout << "Housekeeping: Cleaning suite "
             << roomNumber << " with "
             << numberOfRooms << " rooms (90 minutes)" << endl;
    }

    void deliverRoomService(string orderDetails) {
        cout << "Room Service: VIP delivery of " << orderDetails
             << " to suite " << roomNumber
             << " with full dining setup" << endl;
    }

    double calculatePrice() {
        cout << "Pricing: Suite " << roomNumber
             << " - Rs. 2000/night" << endl;
        return 500.0;
    }

    // many more operations can come over the time
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "problem", "Demo.cpp")] = r'''#include <iostream>
#include "SuiteHotelRoom.h"

using namespace std;

// Usage
int main() {
    cout << "##### Visitor Pattern: Problem Demo #####" << endl;
    SuiteHotelRoom suite("301", "2");
    suite.clean();
    suite.deliverRoomService("Breakfast");
    suite.calculatePrice();

    return 0;
}
'''

# ============================================================
# VISITOR PATTERN - SOLUTION
# ============================================================

# Forward declarations needed for visitor pattern
files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "solution", "elements", "IRoom.h")] = r'''#pragma once

using namespace std;

// Forward declaration
class IRoomVisitor;

// Element interface - represents rooms(elements) that can be visited
class IRoom {
public:
    virtual ~IRoom() = default;

    virtual void accept(IRoomVisitor& visitor) = 0;
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "solution", "visitors", "IRoomVisitor.h")] = r'''#pragma once

using namespace std;

// Forward declarations
class StandardRoom;
class DeluxeRoom;
class SuiteRoom;

// Visitor interface - defines operations
class IRoomVisitor {
public:
    virtual ~IRoomVisitor() = default;

    virtual void visitStandardRoom(StandardRoom& room) = 0;

    virtual void visitDeluxeRoom(DeluxeRoom& room) = 0;

    virtual void visitSuiteRoom(SuiteRoom& room) = 0;
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "solution", "elements", "StandardRoom.h")] = r'''#pragma once

#include <iostream>
#include <string>
#include "IRoom.h"
#include "../visitors/IRoomVisitor.h"

using namespace std;

// Concrete Element - Different room types
class StandardRoom : public IRoom {
private:
    string roomNumber;

public:
    StandardRoom(string roomNumber)
        : roomNumber(roomNumber) {}

    void accept(IRoomVisitor& visitor) override {
        visitor.visitStandardRoom(*this);
    }

    string getRoomNumber() {
        return roomNumber;
    }
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "solution", "elements", "DeluxeRoom.h")] = r'''#pragma once

#include <iostream>
#include <string>
#include "IRoom.h"
#include "../visitors/IRoomVisitor.h"

using namespace std;

// Concrete Element - Different room types
class DeluxeRoom : public IRoom {
private:
    string roomNumber;
    bool jacuzzi;

public:
    DeluxeRoom(string roomNumber, bool hasJacuzzi)
        : roomNumber(roomNumber), jacuzzi(hasJacuzzi) {}

    void accept(IRoomVisitor& visitor) override {
        visitor.visitDeluxeRoom(*this);
    }

    string getRoomNumber() {
        return roomNumber;
    }

    bool hasJacuzzi() {
        return jacuzzi;
    }
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "solution", "elements", "SuiteRoom.h")] = r'''#pragma once

#include <iostream>
#include <string>
#include "IRoom.h"
#include "../visitors/IRoomVisitor.h"

using namespace std;

// Concrete Element - Different room types
class SuiteRoom : public IRoom {
private:
    string roomNumber;
    int numberOfRooms;

public:
    SuiteRoom(string roomNumber, int numberOfRooms)
        : roomNumber(roomNumber), numberOfRooms(numberOfRooms) {}

    void accept(IRoomVisitor& visitor) override {
        visitor.visitSuiteRoom(*this);
    }

    string getRoomNumber() {
        return roomNumber;
    }

    int getNumberOfRooms() {
        return numberOfRooms;
    }
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "solution", "visitors", "HousekeepingVisitor.h")] = r'''#pragma once

#include <iostream>
#include <string>
#include "IRoomVisitor.h"
#include "../elements/StandardRoom.h"
#include "../elements/DeluxeRoom.h"
#include "../elements/SuiteRoom.h"

using namespace std;

// Concrete Visitor - demonstrates adding new operations easily
class HousekeepingVisitor : public IRoomVisitor {
public:
    void visitStandardRoom(StandardRoom& room) override {
        cout << "Housekeeping: Cleaning standard room "
             << room.getRoomNumber() << " (30 minutes)" << endl;
    }

    void visitDeluxeRoom(DeluxeRoom& room) override {
        cout << "Housekeeping: Cleaning deluxe room "
             << room.getRoomNumber()
             << (room.hasJacuzzi() ? " including jacuzzi" : "")
             << " (45 minutes)" << endl;
    }

    void visitSuiteRoom(SuiteRoom& room) override {
        cout << "Housekeeping: Cleaning suite "
             << room.getRoomNumber() << " with "
             << room.getNumberOfRooms() << " rooms (90 minutes)" << endl;
    }
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "solution", "visitors", "PricingVisitor.h")] = r'''#pragma once

#include <iostream>
#include <string>
#include "IRoomVisitor.h"
#include "../elements/StandardRoom.h"
#include "../elements/DeluxeRoom.h"
#include "../elements/SuiteRoom.h"

using namespace std;

// Pricing visitor - demonstrates adding new operations easily
class PricingVisitor : public IRoomVisitor {
private:
    double totalRevenue = 0;

public:
    void visitStandardRoom(StandardRoom& room) override {
        double price = 1000.0;
        totalRevenue += price;
        cout << "Pricing: Standard room " << room.getRoomNumber()
             << " - Rs." << price << "/night" << endl;
    }

    void visitDeluxeRoom(DeluxeRoom& room) override {
        double price = 2000.0;
        totalRevenue += price;
        cout << "Pricing: Deluxe room " << room.getRoomNumber()
             << " - Rs." << price << "/night" << endl;
    }

    void visitSuiteRoom(SuiteRoom& room) override {
        double price = 5000.0;
        totalRevenue += price;
        cout << "Pricing: Suite " << room.getRoomNumber()
             << " - Rs." << price << "/night" << endl;
    }

    double getTotalRevenue() {
        return totalRevenue;
    }
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "solution", "visitors", "RoomServiceVisitor.h")] = r'''#pragma once

#include <iostream>
#include <string>
#include "IRoomVisitor.h"
#include "../elements/StandardRoom.h"
#include "../elements/DeluxeRoom.h"
#include "../elements/SuiteRoom.h"

using namespace std;

// Pricing visitor - demonstrates adding new operations easily
class RoomServiceVisitor : public IRoomVisitor {
private:
    string orderDetails;

public:
    RoomServiceVisitor(string orderDetails)
        : orderDetails(orderDetails) {}

    void visitStandardRoom(StandardRoom& room) override {
        cout << "Room Service: Delivering " << orderDetails
             << " to standard room " << room.getRoomNumber() << endl;
    }

    void visitDeluxeRoom(DeluxeRoom& room) override {
        cout << "Room Service: Premium delivery of " << orderDetails
             << " to deluxe room " << room.getRoomNumber()
             << " with complimentary champagne" << endl;
    }

    void visitSuiteRoom(SuiteRoom& room) override {
        cout << "Room Service: VIP delivery of " << orderDetails
             << " to suite " << room.getRoomNumber()
             << " with full dining setup" << endl;
    }
};
'''

files[os.path.join(base_cpp, "behavioralpatterns", "visitor", "solution", "HotelVisitorDemo.cpp")] = r'''#include <iostream>
#include "elements/StandardRoom.h"
#include "elements/DeluxeRoom.h"
#include "elements/SuiteRoom.h"
#include "visitors/HousekeepingVisitor.h"
#include "visitors/PricingVisitor.h"
#include "visitors/RoomServiceVisitor.h"

using namespace std;

// Usage
int main() {
    cout << "\n###### Visitor Design Pattern Demo ######" << endl;

    // Create different room types(elements) - Standard, Deluxe, Suite
    IRoom* rooms[] = {
        new StandardRoom("101"),
        new DeluxeRoom("201", true),
        new SuiteRoom("301", 3),
        new StandardRoom("102"),
        new DeluxeRoom("202", false)
    };
    int numRooms = 5;

    // Calling Visitors on elements
    cout << "\n==> Housekeeping Service" << endl;
    HousekeepingVisitor housekeeping;
    for (int i = 0; i < numRooms; i++) {
        rooms[i]->accept(housekeeping);
    }

    cout << "\n==> Room Service" << endl;
    RoomServiceVisitor roomService("Breakfast");
    rooms[0]->accept(roomService);  // Deliver to standard room
    rooms[1]->accept(roomService);  // Deliver to deluxe room
    rooms[2]->accept(roomService);  // Deliver to suite

    cout << "\n==> Revenue Calculation" << endl;
    PricingVisitor pricing;
    for (int i = 0; i < numRooms; i++) {
        rooms[i]->accept(pricing);
    }
    cout << "Total Revenue: Rs." << pricing.getTotalRevenue() << endl;

    for (int i = 0; i < numRooms; i++) {
        delete rooms[i];
    }

    return 0;
}
'''

# ============================================================
# MVC PATTERN
# ============================================================

files[os.path.join(base_cpp, "additionalpatterns", "mvc", "model", "Blog.h")] = r'''#pragma once

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Model class: Blog - Holds data about a single blog post.
class Blog {
private:
    string title;
    string content;
    string author;
    time_t createdAt;

public:
    // Constructor
    Blog(string title, string content, string author, time_t createdAt)
        : title(title), content(content), author(author), createdAt(createdAt) {}

    // Getters and Setters
    string getTitle() {
        return title;
    }

    void setTitle(string title) {
        this->title = title;
    }

    string getContent() {
        return content;
    }

    void setContent(string content) {
        this->content = content;
    }

    string getAuthor() {
        return author;
    }

    void setAuthor(string author) {
        this->author = author;
    }

    time_t getCreatedAt() {
        return createdAt;
    }

    void setCreatedAt(time_t createdAt) {
        this->createdAt = createdAt;
    }
};
'''

files[os.path.join(base_cpp, "additionalpatterns", "mvc", "view", "BlogView.h")] = r'''#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "../model/Blog.h"

using namespace std;

// View class: BlogView
// Responsible for displaying blog post details in the console.
// No business logic - just formatting and printing.
class BlogView {
public:
    // Display a single blog post
    void displayBlogDetails(Blog& blog) {
        time_t t = blog.getCreatedAt();
        struct tm* timeinfo = localtime(&t);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);

        cout << "===== Blog Post =====" << endl;
        cout << "Title   : " << blog.getTitle() << endl;
        cout << "Author  : " << blog.getAuthor() << endl;
        cout << "Date    : " << buffer << endl;
        cout << "Content : " << blog.getContent() << endl;
    }

    // Display a list of all blog posts
    void displayAllBlogs(vector<Blog>& blogs) {
        cout << "===== All Blog Posts =====" << endl;
        for (Blog& blog : blogs) {
            cout << "- " << blog.getTitle() << " by " << blog.getAuthor() << endl;
        }
    }
};
'''

files[os.path.join(base_cpp, "additionalpatterns", "mvc", "controller", "BlogController.h")] = r'''#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "../model/Blog.h"
#include "../view/BlogView.h"

using namespace std;

// Controller class: BlogController
// Acts as a bridge between Model (Blog) and View (BlogView).
// Handles creation, updating, and displaying of blog posts.
class BlogController {
private:
    vector<Blog> blogs; // acts as an in-memory database
    BlogView& view;

public:
    // Constructor connects controller with the view
    BlogController(BlogView& view) : view(view) {}

    // Add a new blog post
    void addBlog(string title, string content, string author) {
        Blog blog(title, content, author, time(nullptr));
        blogs.push_back(blog);
        cout << "[+] Blog added successfully!" << endl;
    }

    // Update an existing blog by index
    void updateBlog(int index, string newTitle, string newContent) {
        if (index >= 0 && index < (int)blogs.size()) {
            blogs[index].setTitle(newTitle);
            blogs[index].setContent(newContent);
            cout << "[+] Blog updated successfully!" << endl;
        } else {
            cout << "[+] Invalid blog index!" << endl;
        }
    }

    // Delete a blog post
    void deleteBlog(int index) {
        if (index >= 0 && index < (int)blogs.size()) {
            blogs.erase(blogs.begin() + index);
            cout << "[+] Blog deleted successfully!" << endl;
        } else {
            cout << "[+] Invalid blog index!" << endl;
        }
    }

    // Display a single blog post
    void showBlog(int index) {
        if (index >= 0 && index < (int)blogs.size()) {
            view.displayBlogDetails(blogs[index]);
        } else {
            cout << "[+] Invalid blog index!" << endl;
        }
    }

    // Display all blogs
    void showAllBlogs() {
        view.displayAllBlogs(blogs);
    }
};
'''

files[os.path.join(base_cpp, "additionalpatterns", "mvc", "MVCPatternDemo.cpp")] = r'''#include <iostream>
#include "model/Blog.h"
#include "view/BlogView.h"
#include "controller/BlogController.h"

using namespace std;

// Demonstrates MVC pattern in action for Blog application.
int main() {
    cout << "\n ###### MVC Pattern Demo ###### \n" << endl;

    // Create the view
    BlogView view;

    // Create the controller (connected with the view)
    BlogController controller(view);

    // Add some blog posts
    controller.addBlog("MVC Pattern in Java", "Learn how to structure Java apps using MVC.", "Alice");
    controller.addBlog("Understanding Design Patterns", "Design patterns make your code reusable and clean.", "Bob");
    controller.addBlog("Java Collections Framework", "Learn about different collections and their use cases.", "Charlie");

    // Display all blogs
    controller.showAllBlogs();

    // Show details of a specific blog
    controller.showBlog(0);

    // Update first blog
    controller.updateBlog(0, "MVC Pattern in Java - Updated", "Updated content for the MVC post.");

    // Show updated blog
    controller.showBlog(0);

    // Delete second blog
    controller.deleteBlog(1);

    // Show remaining blogs
    controller.showAllBlogs();

    return 0;
}
'''

# Write all files
for filepath, content in files.items():
    os.makedirs(os.path.dirname(filepath), exist_ok=True)
    with open(filepath, 'w', newline='\n') as f:
        f.write(content.lstrip('\n'))
    print(f"Created: {filepath}")

print("\nAll files generated successfully!")
