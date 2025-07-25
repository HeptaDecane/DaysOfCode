# Object-Oriented Programming (OOP)
**OOP (Object-Oriented Programming)** is a programming paradigm based on the concept of "objects", which can contain data (fields/properties) and code (methods). OOP promotes **modularity, reusability, and maintainability** of code by organizing software into classes and objects.  
- **Class**: A blueprint for creating objects (e.g., Car, Person).

- **Object**: An instance of a class.

### ✅ Benefits of OOP in C#
- Improved code organization.
- Easier maintenance and scalability.
- Promotes modular and reusable code.
- Aligns with real-world modeling.

## 🔑 Four Pillars of OOP in C#
| Concept | Description | C# Implementation |
| --- | --- | --- |
| **Encapsulation** | Hiding internal details and exposing only what’s necessary | Use of `private`, `public`, `internal`, `protected` access modifiers |
| **Abstraction** | Representing essential features without showing background details | Use of `abstract` classes, `interfaces` |
| **Inheritance** | Creating new classes from existing ones to promote code reuse | Use of `:` syntax to inherit from a base class |
| **Polymorphism** | Ability for objects to take many forms, i.e., behave differently in different contexts | Use of method overriding (`virtual`, `override`) or overloading |

## Encapsulation
It refers to the **bundling of data (fields) and methods (functions)** that operate on the data into a single unit (a class), while controlling the access to object's internal state through access modifiers.

### 🎯 Goals of Encapsulation
- **Protect internal state** of an object from unintended or harmful changes.
- **Provide controlled access** through methods or properties (getters/setters).
- **Improve maintainability** and modularity of the code.
- Support **data validation**, consistency, and integrity.

### ✅ Ways C# supports encapsulation:

#### 1. Access Modifiers  
These control the visibility of class members (fields, properties, methods, etc.) from other parts of the code.  
- `private`: Fields or methods are accessible only within the same class. This is the default for fields to hide them from external access.
- `public`: Members are accessible from everywhere. Used for methods that form the public interface.
- `protected`: Members are accessible within the class and its derived classes.
- `internal`: Members are accessible within the same assembly.
- `protected internal`: Members are accessible within the same assembly or derived classes in other assemblies.
- `private protected`: Members are accessible only within the class and derived classes in the same assembly.  

By marking fields as `private` (or similar), you prevent direct external access, a core principle of encapsulation.  

```cs
class Car{
    private int speed; // Cannot be accessed directly outside

    public void SetSpeed(int value){
        if (value >= 0) speed = value;
    }

    public int GetSpeed() {
        return speed;
    }
}

```

#### 2. Properties
C# provides a cleaner syntax using properties with get/set accessors to encapsulate fields while still exposing them safely.  
```cs
class Car {
    private int _speed;

    public int Speed {
        get { return _speed; }
        set {
            if (value >= 0) _speed = value;
        }
    }
}

```
Or using **auto-implemented properties** with access control:
```cs
public class Person
{
    public string Name { get; private set; } // Readable from outside, writable only inside
}

```

#### 3. Methods
Encapsulation often involves exposing functionality through **public methods**, while keeping the implementation **private**.  
```cs
class BankAccount {
    private decimal balance;

    public void Deposit(decimal amount) {
        if (amount > 0) balance += amount;
    }

    public decimal GetBalance() {
        return balance;
    }
}
```

#### 4. Interfaces and Abstraction
While abstraction and encapsulation are distinct, interfaces support encapsulation by hiding the class’s internal details related to implementation.  
```cs
public interface ILogger {
    void Log(string message);
}

public class FileLogger : ILogger {
    private string logFilePath = "log.txt"; // hidden implementation data

    public void Log(string message) {
        // writes to file
    }
}
```

#### 5. Private/Internal Classes and Nested Types
You can restrict access to certain classes entirely by marking them `private` or `internal`.
```cs
public class OuterClass {
    private class InnerHelper {
        public void DoWork() { }
    }
}
```

### Interview Questions
---
#### 1. What is encapsulation in OOP? How is it different from abstraction?
**Encapsulation** in Object-Oriented Programming (OOP) is the bundling of data (attributes) and methods (functions) that operate on that data into a single unit, typically a class, while restricting direct access to some of the object's components. It’s about hiding the internal state of an object and only allowing access through well-defined interfaces, like public methods. This is often achieved using access modifiers (e.g., private, protected, public) to control visibility and ensure data integrity.  
> **Example**: In a `BankAccount` class, the balance is a private attribute. You can only modify it through public methods like `deposit()` or `withdraw()`, which enforce rules (e.g., no negative deposits). This protects the balance from being directly altered in an invalid way.

**Abstraction** in OOP is about hiding complex implementation details and exposing only the essential features of an object to the user. It focuses on *what* an object does, not *how* it does it, often achieved through abstract classes or interfaces.  
> **Example**: A `CoffeeMachine` interface might define a `brew()` method. The user doesn’t need to know the internal mechanics (heating, grinding, etc.)—just that calling `brew()` makes coffee.  

Both concepts work together to make OOP systems modular, secure, and user-friendly, but they address different aspects of design.
- **Purpose**:
   - Encapsulation: Protects an object’s internal state by restricting access and bundling data with methods.
   - Abstraction: Simplifies interaction by hiding complex implementation details and showing only necessary functionality.

- **Focus**:
   - Encapsulation: Focuses on *data security* and bundling.
   - Abstraction: Focuses on *simplifying interaction* and reducing complexity.

**Analogy**:
- Encapsulation is like a locked safe: only specific keys (methods) can access the contents (data).
- Abstraction is like a car’s dashboard: you see simple controls (steering, pedals) without needing to understand the engine’s complexity.

---

#### 2. Why is encapsulation important?
Encapsulation enhances security, data integrity, maintainability, and modularity, making OOP systems more robust and easier to manage.  
> **Example**: In a `User` class, encapsulating a `password` field ensures it can only be modified through a `changePassword()` method that enforces security rules (e.g., minimum length, special characters). This protects the system from invalid or insecure password changes.

---

#### 3. Can you give an example of encapsulation in C#?
- **Private Fields**: The `balance` field is private, preventing direct access from outside the class.
- **Properties**: The `Balance` property provides controlled read/write access with validation. The `AccountHolder` property is read-only after initialization (`init`).
- **Public Methods**: Methods like `Deposit` and `Withdraw` expose functionality while enforcing rules, keeping the internal state consistent.
- **Constructor**: Initializes the object in a valid state, further supporting encapsulation by ensuring proper setup.

---