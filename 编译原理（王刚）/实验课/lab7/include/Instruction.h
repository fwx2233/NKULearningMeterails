#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include "Operand.h"
#include "AsmBuilder.h"
#include <vector>
#include <map>
#include <sstream>

class BasicBlock;
class ExprNode;
class Instruction
{
public:
    Instruction(unsigned instType, BasicBlock *insert_bb = nullptr);
    virtual ~Instruction();
    BasicBlock *getParent();
    bool isUncond() const {return instType == UNCOND;};
    bool isCond() const {return instType == COND;};
    bool isAlloc() const {return instType == ALLOCA;};
    bool isReturn() const {return instType == RET;};
    void setParent(BasicBlock *);
    void setNext(Instruction *);
    void setPrev(Instruction *);
    Instruction *getNext();
    Instruction *getPrev();
    virtual void output() const = 0;
    MachineOperand* genMachineOperand(Operand*);
    MachineOperand* genMachineReg(int reg);
    MachineOperand* genMachineVReg();
    MachineOperand* genMachineImm(int val);
    MachineOperand* genMachineLabel(int block_no);
    virtual void genMachineCode(AsmBuilder*) = 0;
protected:
    unsigned instType;
    unsigned opcode;
    Instruction *prev;
    Instruction *next;
    BasicBlock *parent;
    std::vector<Operand*> operands;
    enum {BINARY, COND, UNCOND, RET, LOAD, STORE, CMP, ALLOCA,MOV,UNARY, FUNCCALL,FUNCDECL,ZEXT, BREAK, CONTINUE};
};

// meaningless instruction, used as the head node of the instruction list.
class DummyInstruction : public Instruction
{
public:
    DummyInstruction() : Instruction(-1, nullptr) {};
    void output() const {};
    void genMachineCode(AsmBuilder*) {};
};

class AllocaInstruction : public Instruction
{
public:
    AllocaInstruction(Operand *dst, SymbolEntry *se, BasicBlock *insert_bb = nullptr);
    ~AllocaInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
private:
    SymbolEntry *se;
};

class ArrayAllocaInstruction : public Instruction
{
    int n;
    SymbolEntry *se;
public:
    ArrayAllocaInstruction(Operand *dst,SymbolEntry *se,int n,BasicBlock *insert_bb = nullptr);
    void output() const {};
    void genMachineCode(AsmBuilder*);
};

class LoadInstruction : public Instruction
{
    ExprNode* arrayno=0;
public:
    LoadInstruction(Operand *dst, Operand *src_addr, BasicBlock *insert_bb = nullptr);
    LoadInstruction(Operand *dst, Operand *src_addr,ExprNode* arrayno ,BasicBlock *insert_bb = nullptr);
    ~LoadInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};

class StoreInstruction : public Instruction
{
    int paramno=-1;
    ExprNode* arrayno=0;
public:
    StoreInstruction(Operand *dst_addr, Operand *src, BasicBlock *insert_bb = nullptr,int paramno=-1);
    StoreInstruction( ExprNode* arrayno,Operand *dst_addr, Operand *src, BasicBlock *insert_bb = nullptr);
    ~StoreInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};

class MovInstruction : public Instruction
{
    bool isGlobal=0;
public:
    MovInstruction(Operand *dst, Operand *src, BasicBlock *insert_bb = nullptr,bool isGlobal=0);
    ~MovInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};

class BinaryInstruction : public Instruction
{
public:
    BinaryInstruction(unsigned opcode, Operand *dst, Operand *src1, Operand *src2, BasicBlock *insert_bb = nullptr);
    ~BinaryInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
    enum {MUL,DIV,MOD,SUB, ADD, AND, OR,XOR};
};

class CmpInstruction : public Instruction
{
public:
    CmpInstruction(unsigned opcode, Operand *dst, Operand *src1, Operand *src2, BasicBlock *insert_bb = nullptr);
    ~CmpInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
    enum {E, NE, L, GE, G, LE};
};

// unconditional branch
class UncondBrInstruction : public Instruction
{
public:
    UncondBrInstruction(BasicBlock*, BasicBlock *insert_bb = nullptr);
    void output() const;
    void setBranch(BasicBlock *);
    BasicBlock *getBranch();
    void genMachineCode(AsmBuilder*);
//protected:
    BasicBlock *branch;
};

// conditional branch
class CondBrInstruction : public Instruction
{
public:
    enum {E, NE, L, GE, G, LE};
    CondBrInstruction(BasicBlock*, BasicBlock*, Operand *, BasicBlock *insert_bb = nullptr);
    ~CondBrInstruction();
    void output() const;
    void setTrueBranch(BasicBlock*);
    BasicBlock* getTrueBranch();
    void setFalseBranch(BasicBlock*);
    BasicBlock* getFalseBranch();
    void genMachineCode(AsmBuilder*);
    void setop(int op){opcode=op;};
protected:
    BasicBlock* true_branch;
    BasicBlock* false_branch;
};

class RetInstruction : public Instruction
{
public:
    RetInstruction(Operand *src, BasicBlock *insert_bb = nullptr);
    ~RetInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};

class BreakInstruction : public UncondBrInstruction
{
public:
    BreakInstruction(BasicBlock* to, BasicBlock* insert_bb = nullptr):UncondBrInstruction(to, insert_bb){}
    ~BreakInstruction(){};
    void output() const;
    void genMachineCode(AsmBuilder*);
};

class ContinueInstruction : public UncondBrInstruction
{
public:
    ContinueInstruction(BasicBlock* to, BasicBlock* insert_bb = nullptr):UncondBrInstruction(to, insert_bb){}
    ~ContinueInstruction(){};
    void output() const;
    void genMachineCode(AsmBuilder*);
};

class UnaryInstruction : public Instruction
{
public:
    UnaryInstruction(unsigned opcode, Operand* dst, Operand *src, BasicBlock *insert_bb=nullptr);    
    ~UnaryInstruction();
    void output() const;
    enum{SUB, ADD, NOT};
    void genMachineCode(AsmBuilder*);
};

class FuncCallInstruction : public Instruction
{
public:    
    FuncCallInstruction(Operand * dst,Operand* ret, std::vector<Operand*>* src,BasicBlock * insert_bb = nullptr);
    ~FuncCallInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};

class DeclareInstruction : public Instruction
{
    SymbolEntry* funcsym;
public:
    DeclareInstruction(SymbolEntry* funcsym,BasicBlock * insert_bb = nullptr);
    ~DeclareInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};

class ZextInstruction : public Instruction
{
    Type * to;
public:
    ZextInstruction(Operand* dst,Operand* src,Type* to,BasicBlock * insert_bb = nullptr);
    ~ZextInstruction();
    void output() const;
    void genMachineCode(AsmBuilder*);
};



#endif
