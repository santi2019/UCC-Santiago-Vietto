package edu.ucc.arqSoft.service.dao;

import org.springframework.stereotype.Repository;

import edu.ucc.arqSoft.service.common.dao.GenericDaoImp;
import edu.ucc.arqSoft.service.model.Register;

@Repository
public class RegisterImpDao extends GenericDaoImp<Register, Long> implements RegisterDao{

}
