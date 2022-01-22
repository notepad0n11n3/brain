
class Transaction
  attr_accessor :user, :date, :concept, :amount

  def salary
    puts "Hello world...!!!"
    1500
  end
end

class Invoice < Transaction
  attr_accessor :number 

  def salary
    super + 400  # SUPER obtine todoEl codigo def salary de class Padre
  end
end


transaction = Transaction.new
invoice = Invoice.new

puts transaction.salary
puts invoice.salary

class Income < Invoice
end
income = Income.new
income.user = "class heredada vacia"  # .user es de class Transaction heredada de Invoice
puts income.user
